class Solution {
public:
    int minimumPushes(string word) {
        map<char,int>mp;
        
        for(auto x: word)
        {
            mp[x]++;
        }
        
        vector<pair<int,char>>vp;
        
        for(auto x: mp)
        {
            vp.push_back({x.second,x.first});
        }
        
        sort(vp.rbegin(),vp.rend());
        
        int ans = 0;
        int n = vp.size();
        
        for(int i=0;i<n;i++)
        {
            ans += (i/8 + 1)*vp[i].first;
            
        }
        return ans;
        
        
    }
};
