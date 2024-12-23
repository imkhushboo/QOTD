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
    	int minSwaps(vector<int>&nums)
	{
	    map<int,int>mp;
	    for(int i=0;i<nums.size();i++)
	    {
	        mp[nums[i]]=i;
	    }
	      vector<int>vp=nums;
	      sort(vp.begin(),vp.end());
	      int cnt=0;
	      for(int i=0;i<nums.size();i++)
	      {
	          if(vp[i]!=nums[i])
	          {
	              int val=nums[i];
	              int temp=mp[vp[i]];
	              swap(nums[i],nums[temp]);
	            mp[val]=temp;
	              cnt++;
	          }
	      }
	      return cnt;
	}
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int cnt=0;
        while(!q.empty())
        {
            int n=q.size();
            vector<int>vt;
            for(int i=0;i<n;i++)
            {
                TreeNode* pt=q.front();
                
                vt.push_back(pt->val);
                q.pop();
                
                if(pt->left)
                {
                    q.push(pt->left);
                }
                if(pt->right)
                {
                    q.push(pt->right);
                }
            }
            cnt+=minSwaps(vt);
        }
        return cnt;
        
        
        
    }
};
