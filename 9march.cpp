class Solution
{
public:
    bool find_binary_search(int target, vector<int> &nums)
    {
        int n = nums.size();

        int low = 0, high = n - 1;
        // cout<<"here"<<"\n";
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
            {
                // cout<<nums[mid] <<" "<<target<<"\n";
                return true;
            }
            else if (nums[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return false;
    }

    int getCommon(vector<int> &nums1, vector<int> &nums2)
    {

        for (auto x : nums1)
        {
            if (find_binary_search(x, nums2))
            {
                return x;
            }
        }

        return -1;
    }
};