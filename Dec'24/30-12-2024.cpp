class Solution {
    
private:
    const int mod = 1e9 +7;
    long long helper(int len, int low, int high,int zero,int one,vector<long long>&dp)
    {
      
        if(len > high) return 0;
        long long takezero = 0,takeone = 0;
        
        if(dp[len] != -1) return dp[len];
        
        if(len>=low and len<=high) 
        {
            takezero++;
            
        }
        
        
        
        // take zero 
        takezero = (takezero + helper(len+zero,low,high,zero,one,dp))%mod;
        // if(len+zero >= low and len<=high) takezero++;
        
        // take one
         takeone =  (takeone + helper(len+one,low,high,zero,one,dp))%mod;
        // if(len >= low and len<=high) takeone++;
        
        // cout<<takeone<<" "<<takelen<<"\n";
        
        return dp[len] = (takezero + takeone)%mod;
        
    }

public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<long long>dp(high+1,-1);
       return helper(0,low,high,zero,one,dp);
        
    }
};
