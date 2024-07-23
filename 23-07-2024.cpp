class Solution {
public:
    
    static bool cmp(pair<int,int>&p1,pair<int,int>&p2)
    {
        if(p1.first == p2.first) return p1.second>p2.second;
        
        return p1.first<p2.first;
    }
    
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int>mp;
        vector<pair<int,int>>vp;
        for(auto x: nums)
        {
            mp[x]++;
        }
        
        for(auto x:mp)
        {
            vp.push_back({x.second,x.first});
        }
        sort(vp.begin(),vp.end(),cmp);
        
        vector<int>ans;
        
        for(auto x: vp)
        {
            int n = x.first;
            
            while(n--)
            {
                ans.push_back(x.second);
            }
        }
        return ans;
        
    }
};
