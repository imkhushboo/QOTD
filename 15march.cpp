
/*
  Product of Array Except Self
  problem - link : https://leetcode.com/problems/product-of-array-except-self/


*/

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        int prefix = 1, suffix = 1;

        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--)
        {
            ans[i] = suffix;
            suffix *= nums[i];
        }

        for (int i = 0; i < n; i++)
        {
            ans[i] = ans[i] * prefix;
            prefix *= nums[i];
        }

        return ans;
    }
};