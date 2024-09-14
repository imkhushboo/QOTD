class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int len = 1;
        int n = nums.size();
        
        vector<pair<int,int>>vt;
        for(int i=1;i<n;i++)
        {
            if(nums[i] == nums[i-1])
            {
                len++;
            }
            else{
                vt.push_back({nums[i-1],len});
                len = 1;
            }
            
        }
        vt.push_back({nums[n-1],len});
        len = 0;
        int ans = 0;
        for(auto x:vt)
        {
            if(ans<x.first)
            {
                ans = x.first;
                len = x.second;
            }
            else if(ans == x.first and len<x.second)
            {
                len = x.second;
            }
        }
        return len;
        
    }
};
