class Solution {
public:
    int countsetbits(int n)
    {
           int count = 0;
            while (n) {
                count += n & 1;
                n >>= 1;
            }
            return count;
    }
    
    bool canSortArray(vector<int>& nums) {
        
        int n = nums.size();
        int flag = 0;
        while(flag == 0)
        {
            flag = 1;
            for(int i=1;i<n;i++)
           { 
            if(nums[i-1]> nums[i])
            {
                flag = 0;
                if(countsetbits(nums[i-1]) == countsetbits(nums[i]))
                {
                    swap(nums[i-1],nums[i]);
                }
                else{
                    return false;
                }
            }
           
           
        }
        }
        
        return true;
        
        
    }
};
