class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k)
    {
        priority_queue<int>pq;
        for (auto x: gifts)   pq.push(x);
        long long ans = 0;
        
        while(k)
        {
            int top = pq.top();
            pq.pop();
            
            int val = sqrt(top);
            pq.push(val);
            k -= 1;
        }
        
        while(!pq.empty())
        {
            ans += pq.top();
            pq.pop();
        }
        
        return ans;
    }};
