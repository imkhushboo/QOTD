class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<bool>ans;
        int n = nums.size();
        
       vector<int>arr(n,0);
        
        for(int i=1;i<n;i++){
            if(nums[i]%2 and nums[i-1]%2){
                arr[i] = arr[i-1]+1;
            }
            else if(nums[i]%2 ==0 and nums[i-1]%2 == 0){
                arr[i] = arr[i-1]+1;
            }
            else{
                arr[i] = arr[i-1];
            }
        }
        
        
        for(auto x:queries){
            ans.push_back(arr[x[0]] == arr[x[1]]);
        }
        
        return ans;
        
    
    }
};

