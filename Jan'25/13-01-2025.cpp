class Solution {
public:
    int minimumLength(string s) {
        int ans = 0;
        unordered_map<char,int>mp;

        for(auto x:s){
            mp[x]++;
        }

        for(auto x:mp){
            if(x.second%2 == 0) ans +=2;
            else ans++;
        }

        return ans;
        
    }
};
