class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
      
        vector<pair<int,int>>vp;
        
        for(int i=0;i<n;i++){
            vp.push_back({nums[i],i});
        }
        
        sort(vp.begin(),vp.end());
        
        vector<int>mark(n,0);
        
        for(int i=0;i<n;i++){
            if(mark[vp[i].second] == 0){
                ans += vp[i].first; 
                if(vp[i].second -1 >=0){
                    mark[vp[i].second - 1] = 1;
                }
                
                if(vp[i].second + 1 < n){
                    mark[vp[i].second + 1] = 1;
                }
            }
        }
        
        return ans;
        
        
        
        
    }
};
