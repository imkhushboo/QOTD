class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        map<int,int>mp;
        int ans = 0;
        for(auto x:candidates){
            for(int i=0;i<32;i++){
                long long val = pow(2,i);
                if(val&x){
                    mp[i]++;
                    ans = max(ans,mp[i]);
                }
            }
        }
        
        return ans;
        
    }
};
