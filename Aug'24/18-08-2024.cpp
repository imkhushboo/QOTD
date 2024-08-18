class Solution {
public:
    int nthUglyNumber(int n) {
    int dp[n];
    dp[0]=1;
    int t1=1,t2=1,t3=1;
    int k[3];
    k[0]=1;
    k[1]=1;
    k[2]=1;
    for(int i=1;i<n;i++){
        dp[i]=min(min(k[0]*2,k[1]*3),k[2]*5);
        if(dp[i]%2==0) {
            k[0]=dp[t1];t1++;}
        if(dp[i]%3==0){
             k[1]=dp[t2]; t2++;
        }
        if(dp[i]%5==0) {k[2]=dp[t3];t3++;}
        
    }     
        
    return dp[n-1];    
     
    }
};
