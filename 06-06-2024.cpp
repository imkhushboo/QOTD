class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        
        if(n%groupSize) return false; 
        map<int,int>mp;
        for(auto x: hand)
        {
            mp[x]++;
        }
        
        vector<int>vp;
        for(auto x:mp)vp.push_back(x.first);

            
        for(auto x: vp)
        {
            int start = x;
            if(mp.find(start) == mp.end()) continue;
            
            for(int j = start ;j<start+groupSize; j++)
            {
                if(mp.find(j) == mp.end()) return false;
                
                mp[j]--;
                if(mp[j] == 0)
                {
                    mp.erase(j);
                }
            }
        }
        
        return true;
        
        
    }
};
