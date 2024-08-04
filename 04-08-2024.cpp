class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>ans;
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                sum += nums[j];
                ans.push_back(sum);
            }
            sum = 0;
        }
        
        sort(ans.begin(),ans.end());
        long long final_res = 0;
        int mod = 1e9+7;
        for(int i = left-1;i<right;i++)
        {
            final_res  =  (final_res + ans[i])%(mod);
        }
        
        return final_res;
        
    }
};
