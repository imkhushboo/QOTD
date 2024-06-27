class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        map<int,int>degree;
        
        for(auto x: edges)
        {
            // cout<<x[0]<<" "<<x[1]<<"\n";
            degree[x[0]]++;
            degree[x[1]]++;
        }
        
        for(auto x:degree)
        {
            if(x.second == n) return x.first;
        }
        return -1;
        
    }
};
