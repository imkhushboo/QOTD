class Solution {
private:
    int BFS(int src, int tar, unordered_map<int, vector<int>>& adj)
    {
        queue<pair<int, int>>q;
        q.push({src, 0});
        // vector<bool>vis(tar+1, false);
        // vis[src] = true;
        
        while(!q.empty())
        {
            int size = q.size();
            while(size --)
            {
                int top = q.front().first;
                int count = q.front().second;
                q.pop();
                
                if (top == tar)   return count;
                
                for (auto x: adj[top])
                {
                    if (!vis[x])   
                    {
                        q.push({x, count + 1});
                        vis[x] = true;
                    }
                }
            }
        }
        
        return -1;
    }
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) 
    {
        unordered_map<int, vector<int>>mp;
        for (int i=0;i<n-1;i++)
        {
            mp[i].push_back(i+1);
        }
        
        int size = queries.size();
        vector<int>ans(size, 0);
        
        for (int i=0;i<size;i++)
        {
            int from = queries[i][0];
            int to = queries[i][1];
            mp[from].push_back(to);
            
            int step = BFS(0, n-1, mp);
            ans[i] = step;
        }
        
        return ans;
    }
};
