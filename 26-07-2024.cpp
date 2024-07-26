class Solution {
private : 
    // dijkstra's algo 
    int dijkstra(int node,int n ,vector<pair<int,int>>adj[],int distanceThreshold)
    {
      
        vector<int>dist(n,1e9);
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,node});
        dist[node] = 0;
        
        
        while(!pq.empty())
        {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            
            for(auto it :adj[node])
            {
                int v = it.first;
                int wt = it.second;
                
                if(dis + wt <= distanceThreshold and (dis + wt < dist[v]))
                {
                    dist[v] = dis + wt;
                    pq.push({dist[v],v});
                }
            }
        }
        
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            if(dist[i] !=0 and dist[i] != 1e9)
            {
                cnt++;
            }
        }
        return cnt;
        
    }
    
    

    
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int m = edges.size();
        
        vector<pair<int,int>>adj[n];
        
        for(int i=0;i<m;i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
      
        int totalCities = n-1;
        int ans = -1;
        
        for(int i=0;i<n;i++)
        {
         int citiesVisited =  dijkstra(i , n, adj,  distanceThreshold);
         // cout<<citiesVisited<<"\n";
            
            if(citiesVisited <= totalCities)
            {
                totalCities = citiesVisited;
                ans = i;
            }
        }
        
        return ans;
        
    }
};
