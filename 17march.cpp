class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {

        vector<vector<int>> ans;

        intervals.push_back(newInterval);

        sort(intervals.begin(), intervals.end());
        int n = intervals.size();

        //         for(auto x:intervals)
        //         {
        //             cout<<x[0]<<" "<<x[1]<<"\n";
        //         }

        ans.push_back(intervals[0]);
        for (int i = 1; i < n; i++)
        {
            int m = ans.size();
            if (m >= 1 && (ans[m - 1][1] >= intervals[i][0]))
            {
                ans[m - 1][1] = max(ans[m - 1][1], intervals[i][1]);
            }
            else
            {
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};