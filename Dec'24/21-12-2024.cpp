class Solution {
public:
    int cnt = 0;
    bool dfs(int node,unordered_map<int,vector<int>>&mp,vector<int>&vis,int k,vector<int>& values,long long int& sum)
    {
        sum += values[node]; 
        
        
        vis[node] = 1;
       
       
        
        for(auto x:mp[node]){
            if(!vis[x])
            {
                long long int childsum = 0;
                if(!dfs(x,mp,vis,k,values,childsum)){
                     sum += childsum;
                }
            }
        }
        
        if(sum % k == 0) {
            // cout<<sum<<"\n";
            cnt++;
            return true;
        }
        return false;
        
    }
    
    
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        unordered_map<int,vector<int>>mp;
        
        for(auto x:edges){
            mp[x[0]].push_back(x[1]);
            mp[x[1]].push_back(x[0]);
        }
        
        
        vector<int>vis(n,0);
       
       
        long long int sum = 0;
        dfs(0,mp,vis,k,values,sum);
       
        
        return cnt;
        
        
    }
};
