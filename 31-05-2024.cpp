class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
       int n = nums.size();
        
        unsigned int xorr = nums[0];
        for(int i=1;i<n;i++)
        {
            xorr^=nums[i];
        }
        
        int one = 0;
        int two = 0;
        
        int rightmost = (xorr & (xorr-1))^xorr;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i] & rightmost)
            {
                one^=nums[i];
            }
            else{
                two^=nums[i];
            }
        }
        
        return {one,two};
        
    }
};
