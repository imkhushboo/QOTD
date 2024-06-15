class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital)
    {
        int n = profits.size();
        vector<pair<int, int>>vec;
        for (int i=0;i<profits.size();i++)    vec.push_back({capital[i], profits[i]});
        sort(vec.begin(), vec.end());
        
        int ans = w;
        int ind = 0;
        priority_queue<int>pq;
        
        while(k--)
        {
            while(ind < n and w >= vec[ind].first)
            {
                pq.push(vec[ind].second);
                ind += 1;
            }
            
            if (pq.empty())    break;
            
            ans += pq.top();
            w += pq.top();
            pq.pop();
            
        }
        
        return ans;
    }
};
