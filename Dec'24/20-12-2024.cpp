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
    TreeNode* reverseOddLevels(TreeNode* root) {
    
        
        queue<TreeNode*>q;
        q.push(root);
        vector<int>vp;
        int level=0;
        while(!q.empty())
        {
            int n=q.size();
          
            for(int i=0;i<n;i++)
            {
                TreeNode* node=q.front();
                q.pop();
               
                if(level==0)
                {
                     //even level
                    if(node->left) 
                    {
                        vp.push_back(node->left->val);
                    }
                    if(node->right)
                    {
                         vp.push_back(node->right->val);
                    }
                       
                }
                else{
                    //odd level
                    node->val=vp[i]; 
                }
                if(node->left)  
                {
                    q.push(node->left);
                } 
                if(node->right) 
                {
                    q.push(node->right);
                }
                
            }
            if(level==1)
            {
                vp.clear();
            }
            else{
                reverse(vp.begin(),vp.end());
            }
           
            level=1-level;
        }
        return root;
        
    }
};
