class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int i=0,j=0;
        int n=nums.size();
        map<int,int>mp;
        int sum=nums[0];
        for(int i=1;i<n;i++)
        {
            int temp=sum;
            sum+=nums[i];
            // cout<<sum<<"\n";
            if(sum%k==0) return true;
            
            int val=(sum%k);
            // cout<<val<<"\n";
            if(mp[val]>=1) return true;
            
            mp[temp%k]++;
        }
        return false;
    }
};
