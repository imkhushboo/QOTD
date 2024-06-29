class Solution {
public:
    
    void helper(int i,vector<vector<int>>&adj,vector<int>&ans)
    {
        int n = adj.size();
        if(adj[i].size() == 0) return;
        
        for(auto x: adj[i])
        {
            if(find(ans.begin(),ans.end(),x) == ans.end())
            {
               helper(x,adj,ans);
                ans.push_back(x);  
            }
          
        }
        
        return;
        
    }
    
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        
        for(auto x: edges)
        {
            adj[x[1]].push_back(x[0]);
        }
        vector<vector<int>>ans(n);
        
        for(int i=0;i<n;i++)
        {
            vector<int>vec;
            helper(i,adj,vec);
            sort(vec.begin(),vec.end());
            ans[i] = vec;
            
        }
        return ans;
        
    }
};
