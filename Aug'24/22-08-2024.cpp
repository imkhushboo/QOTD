class Solution {
private:
    void numTOBIN(int num, vector<int>& arr)
    {
        while(num > 0)
        {
            int rem = num % 2 ;
            if (rem == 0)   arr.push_back(1);
            if (rem == 1)   arr.push_back(0);
            num = num / 2;
        }
    }
    
    int binTONUM(vector<int>& nums)
    {
        int ans = 0;
        int power = 0;
        reverse(nums.begin(), nums.end());
        for (int i=0;i<nums.size();i++)
        {
            if (nums[i] == 1)
            {
                ans += pow(2, power);
            }
            power += 1;
        }
        return ans;
    }
public:
    int findComplement(int num) 
    {
        vector<int>nums;
        numTOBIN(num, nums);
        reverse(nums.begin(), nums.end());
        
        int ans = binTONUM(nums);
        return ans;
    }
};
