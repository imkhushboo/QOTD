class Solution {
public:
    bool canConstruct(string s, int k) {

        if(s.size()<k) return false;
        unordered_map<char,int>mp;

        for(auto x:s){
            mp[x]++;
        }

       int cnt = 0;
        for(auto x:mp)
        {

            if(x.second % 2){
                cnt++;
            }

            if(cnt >k) return false;

        }

        return true;
        
    }
};
