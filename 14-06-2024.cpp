class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans = 0;
        
        for(int i=1;i<n;i++)
        {
            if(nums[i-1] >= nums[i])
            {
                // cout<<nums[i-1]<<" "<<nums[i]<<"\n";
            ans += abs(nums[i-1] + 1 - nums[i]);
            nums[i]= nums[i-1] + 1;    
            }
            
        }
        return ans;
        
    }
};
