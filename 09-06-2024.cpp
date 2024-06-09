class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
       map<int,int>mp;
        mp[0] = 1;
        
        int sum = 0;
        int ans = 0;
        for(auto x:nums)
        {
            sum += x;
            // cout<<sum%k<<"\n";
            if(mp.find((k + sum%k)%k) != mp.end())
            {
                ans+= mp[(k + sum%k)%k];
            }
            mp[(k + sum%k)%k]++;
            
        }
        return ans;
      
    }
};
