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
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL) return {};
        vector<int>vp;
        queue<TreeNode*>pq;
        pq.push(root);
        while(!pq.empty())
        {
            // vp.push_back(pq.front());
            int n=pq.size();
            int ans=INT_MIN;
            for(int i=0;i<n;i++)
            {
                TreeNode* node=pq.front();
                ans=max(ans,node->val);
                pq.pop();
                if(node->left)
                {
                    pq.push(node->left);
                }
                if(node->right)
                {
                    pq.push(node->right);
                }
            }
             vp.push_back(ans);
            
        }
        return vp;
    }
};
