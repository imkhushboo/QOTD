class Solution {
     unordered_map<char, unordered_map<char, long long>> memo;
private:
    long long dijkstra(char src, char tar, unordered_map<char, vector<pair<char, long long>>> &mp)
    {
         if (memo[src].find(tar) != memo[src].end()) return memo[src][tar];
        
        priority_queue<pair<long long, char>, vector<pair<long long, char>>, greater<pair<long long, char>>> pq;
        unordered_map<char, long long>distance;
        
        pq.push({0, src});
        distance[src] = 0;
        
        while(!pq.empty())
        {
            long long topCost = pq.top().first;
            char topChar = pq.top().second;
            pq.pop();
            
            if (topChar == tar) 
            {
                memo[src][tar] = topCost;
                return topCost;
            }
            
            for (auto x:mp[topChar])
            {
                char mpChar = x.first;
                long long mpCost = x.second;
                
                if (distance.find(mpChar) == distance.end() or topCost + mpCost < distance[mpChar])
                {
                    distance[mpChar] = topCost + mpCost;
                    pq.push({distance[mpChar], mpChar});
                }
            }
            
        }
        
        memo[src][tar] = -1;
        return -1;
    }
    
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) 
    {
        unordered_map<char, vector<pair<char, long long>>>mp;
        for (int i = 0; i < original.size(); ++i)
        {
            mp[original[i]].push_back({changed[i], cost[i]});
        }
        
        long long ans = 0;
        for (int i = 0; i < source.size(); ++i)
        {
            if (source[i] != target[i]) 
            {
                long long Cost = dijkstra(source[i], target[i], mp);
                if (Cost == -1)      return -1;
                ans += Cost;
            }
        }
        
        return ans; 
    }
};
