class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        
        for(int i=0;i<n;i++)
        {
            int val = abs(nums[i]);
            if(nums[val]>0)
            {
                nums[val] = - nums[val];
            }
            else{
                return val;
            }
        }
        
        
        return -1;
        
    }
};