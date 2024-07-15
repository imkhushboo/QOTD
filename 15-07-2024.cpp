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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
         map<int,TreeNode*>mp;
        map<int,TreeNode*> parmp;
        for(auto x: descriptions)
        {
            TreeNode* par = mp.find(x[0]) == mp.end() ? new TreeNode(x[0]):mp[x[0]];
            TreeNode* child = mp.find(x[1]) == mp.end()? new TreeNode(x[1]) : mp[x[1]];
            
            if(x[2] == 1)
            {
                par->left = child;
            }
            else{
                par->right = child;
            }
            
            mp[x[0]] = par;
            mp[x[1]] = child;
            parmp[x[1]] = par;
        }
        
        for(auto x:mp)
        {
            if(parmp.find(x.first) == parmp.end()) return x.second;
        }
        return NULL;
                                      
                                      
                
                                      
                            
        
    }
};
