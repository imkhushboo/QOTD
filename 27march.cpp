class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        int n = nums.size();

        int i = 0, j = 0;
        int prod = 1;
        int ans = 0;
        while (j < n)
        {
            prod *= nums[j];

            while (i <= j and prod >= k)
            {
                prod /= nums[i];
                i++;
            }

            if (prod < k)
            {
                ans += (j - i + 1);
            }
            j++;
        }

        return ans;
    }
};