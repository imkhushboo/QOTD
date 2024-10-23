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
    TreeNode* replaceValueInTree(TreeNode* root) {
        root->val = 0;
        queue<TreeNode*>q;
        q.push(root);
        
        
        while(!q.empty()){
            int n = q.size();
            queue<TreeNode*>q2;
            int summ = 0;
            for(int i=0;i<n;i++){
                TreeNode* node = q.front();
                if(node->left){
                    summ += node->left->val;
                }
                
                
                if(node->right){
                    summ += node->right->val;
                }
                
                q2.push(node);
                q.pop();
            }
            
            while(!q2.empty()){
                TreeNode* node = q2.front();
                q2.pop();
                
                int sib_sum = 0;
                if(node->left){
                    sib_sum += node->left->val;
                    
                }
                
                if(node->right){
                    sib_sum += node->right->val;
                }
                
                if(node->left){
                    node->left->val = summ - sib_sum;
                    q.push(node->left);
                }
                
                if(node->right){
                    node->right->val = summ - sib_sum;
                        q.push(node->right);
                }
            }
        }
        
        return root;
        
        
    }
};
