class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0;
        
        int i = 0, j = 0;
        
        int n = nums.size();
        map<int,int>mp;
        long long sum = 0;
        while(j<n){
            mp[nums[j]]++;
            sum += nums[j];
            // cout<<i<<" "<<j<<"\n";
            
            if(j - i + 1 ==k){
              
                
                while(mp.size() != j-i+1){
                    mp[nums[i]]--;
                    sum -= nums[i];
                    if(mp[nums[i]] == 0){
                        mp.erase(nums[i]);
                    }
                    i++;
                }
                
                  if(j-i+1 == k and mp.size() == j-i+1){
                    // cout<<sum<<"\n";
                     ans = max(ans,sum);
                      mp[nums[i]]--;
                    sum -= nums[i];
                    if(mp[nums[i]] == 0){
                        mp.erase(nums[i]);
                    }
                      i++;
                }
                
                
            }
            
            
            j++;
            
        }
        
        return ans;
        
    }
};
