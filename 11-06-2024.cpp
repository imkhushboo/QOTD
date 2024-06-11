class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int>mp;
        
        for(auto x: arr1)
        {
            mp[x]++;
        }
        
        vector<int>ans;
        
        for(auto x: arr2)
        {
            while(mp[x])
            {
                ans.push_back(x);
                mp[x]--;
                if(mp[x] == 0)
                {
                    mp.erase(x);
                }
            }
        }
        
        for(auto x: mp)
        {
            int freq = x.second;
            int val = x.first;
            while(freq--)
            {
                ans.push_back(val); 
            }
           
        }
        
        return ans;
    }
};
