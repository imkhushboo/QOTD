class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        
        vector<pair<int,int>>vec;
        int n = profit.size();
        
        for(int i=0;i<n;i++)
        {
            vec.push_back({difficulty[i],profit[i]});
        }
        
        sort(vec.begin(),vec.end());
        
        int m = worker.size();
        int ans = 0;
        for(int i=0;i<m;i++)
        {
            int cost = 0;
            for(int j=0;j<n;j++)
            {
                if(worker[i]>= vec[j].first)
                {
                    cost = max(cost,vec[j].second);
                }
                else{
                    break;
                }
            }
            
            ans+=cost;
        }
        return ans;
    }
};
