/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    TreeNode* helper(int i,int j,vector<int>&vec){
        if(i>j) return NULL;
        int mid = i + (j-i)/2;
        TreeNode* root = new TreeNode(vec[mid]);
        
        root->left = helper(i,mid-1,vec);
        root->right = helper(mid+1,j,vec);
        
        return root;
        
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>vec;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            vec.push_back(node->val);
            q.pop();
            
            if(node->left){
                q.push(node->left);
            }
            if(node->right)
            {
                q.push(node->right);
            }
        }
        
        sort(vec.begin(),vec.end());
        return helper(0,vec.size()-1,vec);
        
        
    }
};
