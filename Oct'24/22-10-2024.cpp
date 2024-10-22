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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        
        queue<TreeNode*>q;
        q.push(root);
        
        vector<long long>vt;
        while(!q.empty()){
            int n = q.size();
            long long value = 0;
            for(int i=0;i<n;i++){
                TreeNode* node = q.front();
                value += node->val;
                q.pop();
                
                if(node->left){
                    q.push(node->left);
                }
                
                if(node->right){
                    q.push(node->right);
                }
                
            }
            vt.push_back(value);
        }
        
        
        sort(vt.rbegin(),vt.rend());
        
        if(k>vt.size()) return -1;
        return vt[k-1];
        
        
    }
};
