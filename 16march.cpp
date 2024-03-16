class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> mp;

        int sum = 0;
        int ans = 0;

        mp[0] = -1;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                sum -= 1;
            }
            else
            {
                sum += 1;
            }

            if (mp.find(sum) != mp.end())
            {
                ans = max(ans, i - mp[sum]);
            }
            else
                mp[sum] = i;
        }

        return ans;
    }
};