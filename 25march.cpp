class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> vec;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            int val = abs(nums[i]);

            if (nums[val - 1] > 0)
            {
                nums[val - 1] = -nums[val - 1];
            }
            else
            {
                vec.push_back(val);
            }
        }

        return vec;
    }
};