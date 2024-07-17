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
    unordered_map<int,pair<TreeNode*,TreeNode*>>par;
    void helper(TreeNode* root)
    {
        if(root == NULL) return;
        
        if(root->left)
        {
            par[root->left->val] = {root->left,root};
            helper(root->left);
        }
        
        if(root->right)
        {
            par[root->right->val] = {root->right,root};
            helper(root->right);
        }
        
    }
    
    
    bool isleftChild(TreeNode* root,int value)
    {
        return (root and root->left and root->left->val == value);
    }
    
    bool isrightChild(TreeNode* root,int value)
    {
        return (root and root->right and root->right->val == value);
    }
  
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        par[root->val] = {root,NULL};
        helper(root);
        
        for(auto x: to_delete)
        {
            
            TreeNode* parent = par[x].second;
            TreeNode* self = par[x].first;

            if(self->left)
            {
                par[self->left->val] = {self->left,NULL};
            }

            if(self->right)
            {
                par[self->right->val] = {self->right,NULL};
            }

            if(isleftChild(parent,x))
            {
                parent->left = NULL;
            }
            else if(isrightChild(parent,x)){
                parent->right = NULL;
            }
            
            par.erase(x);
            
        }
        
        vector<TreeNode*>ans;
        
        for(auto x:par)
        {
            if(x.second.second == NULL)
            {
                ans.push_back(x.second.first);
            }
        }
        
        return ans;
        
        
    }
};
