class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double ans = 0;
        int pre_time = 0;
        int n = customers.size();
        for(auto x: customers)
        {
            if(pre_time > x[0])
            {
                 ans += (pre_time + x[1] - x[0]);
                pre_time += x[1];
            } 
            else
            {
                ans += x[1];
                pre_time = x[0] + x[1];
            }
            
            // cout<<ans<<" ";
               
            
        }
        
        return ans/(double)n;
        
    }
};
