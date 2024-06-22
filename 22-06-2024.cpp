class Solution {
public:
     int helper(vector<int>& nums, int goal) {
          map<int,int>mp;
          int n=nums.size();
        int sum=0,cnt=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(sum==goal) cnt++;
            if(mp.count(sum-goal)){
                cnt+=(mp[sum-goal]);
                
            }
            mp[sum]++;
        }
        return cnt;
        
    }
    
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i=0;i<nums.size() ;i++)
        {
            nums[i]%=2;
        }
        return helper(nums,k);
        
    }
};
