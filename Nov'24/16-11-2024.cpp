class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int>ans;
        int n  = nums.size();
        
        for(int i=0;i<=n-k;i++){
            bool flag = false;
            for(int j = i+1;j<i+k;j++){
                if(nums[j] <= nums[j-1] or nums[j] - 1 != nums[j-1]){
                    flag = true;
                    break;
                }
            }
            
            if(flag ==false){
                ans.push_back(nums[i+k-1]);
            }
            else{
                ans.push_back(-1);
            }
        }
        
        
        return ans;
    }
};
