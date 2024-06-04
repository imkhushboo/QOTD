class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int>mp;
        for(auto x:s){
            mp[x]++;
        }
        int ans=0,res=0;
        for(auto x:mp){
            if(x.second %2 ==0){
                ans+=x.second;
            }
            else{
                ans+=x.second-1;
                res=1;
            }
        }
        return ans+res;
    }
};
