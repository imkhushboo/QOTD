class Solution {
public:
    
//     long long helper(int i, int j,vector<int>&robot,vector<int>factory,vector<vector<long long>>&dp){
//         int n = robot.size();
//         int m = factory.size();
        
//         if(i == n) return 0;
//         else if(j == m) return 1e18;
        
//         if(dp[i][j] != -1) return dp[i][j];
        
//         // take factory
//         long long ans = abs(factory[j]-robot[i])+helper(i+1,j+1,robot,factory,dp);
        
//         ans = min(ans,helper(i,j+1,robot,factory,dp));
//         return dp[i][j] = ans;
//     }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        int n = robot.size();
       
        sort(factory.begin(),factory.end());
        sort(robot.begin(),robot.end());
       vector<int>new_factory;
        
        for(auto x:factory){
            while(x[1]>0){
                new_factory.push_back(x[0]);
                x[1]--;
            }
        }
         int m = new_factory.size();
        
        vector<vector<long long>>dp(n+1,vector<long long>(m+1,-1));
        
        
        for(int j=0;j<m;j++){
            dp[n][j] = 0;
        }
        
        for(int i=0;i<n;i++){
            dp[i][m] = 1e18;
        }
        
        dp[n][m] = 0;
        
        for(int i = n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                   // take factory
                long long ans = abs(new_factory[j]-robot[i])+dp[i+1][j+1];

                ans = min(ans,dp[i][j+1]);
                dp[i][j] = ans;
            }
        }
        
        return dp[0][0];
    }
};
