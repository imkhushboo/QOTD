class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        bool ismini = false;
        bool ismaxi = false;
        int minind = -1;
        int maxind = -1;
        long long cnt = 0;

        int start = 0, end = 0;

        int n = nums.size();

        while (end < n)
        {
            if (nums[end] < minK or nums[end] > maxK)
            {
                ismini = false;
                ismaxi = false;
                start = end + 1;
            }

            if (nums[end] == minK)
            {
                ismini = true;
                minind = end;
            }

            if (nums[end] == maxK)
            {
                ismaxi = true;
                maxind = end;
            }

            if (ismini and ismaxi)
            {
                cnt += min(minind, maxind) - start + 1;
            }
            end++;
        }

        return cnt;
    }
};