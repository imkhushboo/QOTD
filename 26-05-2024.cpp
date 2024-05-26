class Solution {
private:
    const int mod = 1e9 + 7;
    int dp[2][3][100001];
    int helper(int absent, int cnt,int i,int n)
    {
        if( i == n) {
            return 1;
        }
        
        if(dp[absent][cnt][i] != -1) return dp[absent][cnt][i];
        
        //logic
        int ans = 0;

       // choose P
        ans = (ans + helper(absent,0,i+1,n))%mod;

        // choose A

        if(absent == 0)
        {
            ans = (ans + helper(1,0,i+1,n))%mod;
        }


        // choose L

        if(cnt <2)
        {
            ans = (ans + helper(absent,cnt+1,i+1,n))%mod;
        }


        
       return dp[absent][cnt][i] = ans;
    }
public:
    int checkRecord(int n) {
        memset(dp,-1,sizeof(dp));
        return helper(0,0,0,n);
    }
};
