class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        map<int,int>mp1,mp2;
        
        for(auto x: target)
        {
            mp1[x]++;
        }
        
        for(auto x: arr)
        {
            mp2[x]++;
        }
        
        
        for(auto x: mp2)
        {
            if(x.second != mp1[x.first]) return false;
        }
        
        return true;
        
    }
};
