class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper)
    {
        sort(nums.begin(), nums.end());
        long long ans = 0;
        
        for (int i=0;i<nums.size();i++)
        {
            long long  lowPoint = lower - nums[i];
            long long  highPoint = upper - nums[i];
            
            auto lowCals  = lower_bound(nums.begin() + i + 1, nums.end(), lowPoint);
            auto highCals = upper_bound(nums.begin() + i + 1, nums.end(), highPoint);
            
            ans += highCals - lowCals;
        }
        
        return ans;
    }
};
