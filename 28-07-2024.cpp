class Solution {
private:
    int dijkstra(int src, int tar, map<int, vector<int>>& mp, int time, int change) 
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> distance1(tar + 1, INT_MAX);
        vector<int> distance2(tar + 1, INT_MAX);
        
        distance1[src] = 0;
        pq.push({0, src});
        
        while (!pq.empty()) {
            int cost = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for (auto neighbor : mp[node])
            {
                int travelTime = time;
                int TimeTaken = cost + travelTime;
                
                if ((cost / change) % 2 == 1) {
                    TimeTaken += (change - (cost % change));
                }
                
                if (distance1[neighbor] > TimeTaken) 
                {
                    distance2[neighbor] = distance1[neighbor];
                    distance1[neighbor] = TimeTaken;
                    pq.push({distance1[neighbor], neighbor});
                } 
                else if (TimeTaken > distance1[neighbor] && TimeTaken < distance2[neighbor])
                {
                    distance2[neighbor] = TimeTaken;
                    pq.push({distance2[neighbor], neighbor});
                }
            }
        }
        
        return distance2[tar];
    }
    
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        map<int, vector<int>> mp;
        for (auto edge : edges)
        {
            mp[edge[0]].push_back(edge[1]);
            mp[edge[1]].push_back(edge[0]);
        }
        
        return dijkstra(1, n, mp, time, change);
    }
};
