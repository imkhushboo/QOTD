class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i = 0,j =0;
        int n = nums.size();
        int ans = 0;
        while(j<n){
            
            if(nums[j] - nums[i] <= 2*k){
                ans = max(ans,j-i+1);
            }
            
            while(nums[j] - nums[i] > 2*k){
                i++;
            }
            
            j++;
            
        }
        
        return ans;
            
        
    }
};



