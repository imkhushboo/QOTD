class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<pair<int,int>>vp;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<nums[i].size();j++)
            vp.push_back({nums[i][j],i});
        }
        
        sort(vp.begin(),vp.end());
        
        int i=0,j=0;
        
        unordered_map<int,int>mp;
        
        int len = INT_MAX;
        vector<int>ans(2);
        while(j<vp.size()){
            
            mp[vp[j].second]++;
            
            while(mp.size() >= n){
                if(mp.size() == n){
                    
                    if(len > vp[j].first - vp[i].first)
                    {
                        len = vp[j].first - vp[i].first;
                        ans[0] = vp[i].first;
                        ans[1] = vp[j].first;
                    }
                    
                }
                
                mp[vp[i].second]--;
                
                if(mp[vp[i].second] == 0){
                    mp.erase(vp[i].second);
                }
                
                i++;
                
            }
            
            j++;
            
        }
        
        return ans;
    }
};
