class Solution {
public:
    int helper(int i,vector<int>&nums,int target)
    {
        int n=nums.size();
        if(i>=n) return target==0;
        
        return helper(i+1,nums,target-nums[i])+helper(i+1,nums,target+nums[i]);
        
        
        
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        return helper(0,nums,target);
        
    }
};
