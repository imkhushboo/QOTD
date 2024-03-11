lass Solution {
public:
    string customSortString(string order, string s) {
        string ans = "";
           
        unordered_map<char,int>mp;
        
        for(auto x: s)
        {
            mp[x]++;
        }
        
        
        for(auto x: order)
        {
            int n = mp[x];
            while(n--)
            {
                ans += x;
            }
            mp[x] = 0;
        }
     
        
       for(auto x: mp)
       {

           int n = x.second;
           while(n--)
           ans += x.first;
        
       }
        
        return ans;
     
    }
};