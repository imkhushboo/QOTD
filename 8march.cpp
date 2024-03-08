class Solution
{
public:
    int maxFrequencyElements(vector<int> &nums)
    {
        map<int, int> mp;

        for (auto x : nums)
        {
            mp[x]++;
        }

        int maxi = 0;
        int ans = 0;
        for (auto x : mp)
        {
            if (maxi < x.second)
            {
                maxi = x.second;
                ans = x.second;
            }
            else if (maxi == x.second)
            {
                ans += x.second;
            }
        }

        return ans;
    }
};