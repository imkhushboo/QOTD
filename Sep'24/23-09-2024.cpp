class Solution {
public:
    int dp[51];
    int helper(string s,vector<string>&dictionary,int i,int j)
    {
        int n=s.size();
        // cout<<i<<" "<<j<<"\n";
        if(j>=n && i>=n) return 0;
        if(j==n) return j-i+1;
        if(dp[i]!=-1) return dp[i];
        int ans=INT_MAX;
        if(find(dictionary.begin(),dictionary.end(),s.substr(i,j-i+1))!=dictionary.end())
        {
           ans=min(ans, helper(s,dictionary,j+1,j+1));
        }
        else{
           ans=min(ans,j-i+1+helper(s,dictionary,j+1,j+1));
        }
        ans=min(ans,helper(s,dictionary,i,j+1));
        return dp[i]=ans;
        
    }
    int minExtraChar(string s, vector<string>& dictionary) {\
        memset(dp,-1,sizeof(dp));
        return helper(s,dictionary
