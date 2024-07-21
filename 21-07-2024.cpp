class Solution {
public:
    
    vector<int>topo_sort(int k ,vector<vector<int>>&arr)
    {
        vector<vector<int>>adj(k+1);
        
        vector<int>indegree(k+1,0);
        
        for(auto x: arr)
        {
            adj[x[0]].push_back(x[1]);
            indegree[x[1]]++;
        }
        queue<int>q;
        for(int i=1;i<=k;i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty())
        {
            int node = q.front();
            // cout<<node<<"\n";
            ans.push_back(node);
            q.pop();
            
            for(auto x: adj[node])
            {
                // cout<<x<<"--\n";
                indegree[x]--;
                
                if(indegree[x] == 0)
                {
                    q.push(x);
                }
            }
        }
    
        
        return ans;
    }
    
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int>row1 = topo_sort(k,rowConditions);
        vector<int>col1 = topo_sort(k,colConditions);
        
        if( row1.size()!= k or col1.size() != k) return {};
        
        
        vector<vector<int>>ans(k,vector<int>(k,0));
        
        for(int i=0;i<k;i++)
        {
            int j = find(col1.begin(),col1.end(),row1[i]) - col1.begin();
            ans[i][j] = row1[i];
        }
        
        return ans;
        
        
    }
};
