class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {

        unordered_map<char, int> mp;

        for (auto x : tasks)
        {
            mp[x]++;
        }

        priority_queue<int> pq;

        for (auto x : mp)
        {
            pq.push(x.second);
        }
        int ans = 0;

        while (!pq.empty())
        {
            int repeat = n + 1;
            vector<int> temp;
            while (repeat > 0 && !pq.empty())
            {
                int fre = pq.top();
                pq.pop();
                fre--;
                repeat--;
                ans++;
                if (fre > 0)
                    temp.push_back(fre);
            }

            for (auto x : temp)
            {
                // cout<<x<<"\n";
                pq.push(x);
            }
            if (pq.empty())
                break;
            ans += repeat;
        }

        return ans;
    }
};