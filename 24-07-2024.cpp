class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int,pair<int,int>>>vp;
        
        for(int i=0;i<nums.size();i++)
        {
            int n = nums[i];
            int val = 0;
            int carry = 0;
            while(n>0)
            {
                val += mapping[n%10]*(pow(10,carry++));
                n/=10;
                
            }
            
            if(nums[i] == 0) vp.push_back({mapping[0],{i,nums[i]}});
            
            else vp.push_back({val,{i,nums[i]}});
        }
        
        sort(vp.begin(),vp.end());
        
        vector<int>ans;
        
        for(auto x:vp)
        {
            
            ans.push_back(x.second.second);
        }
        
        return ans;
        
    }
};
