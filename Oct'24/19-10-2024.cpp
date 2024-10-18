class Solution {
public:
    
    int ans = 0;
    int val = 0;
    void helper(int i,vector<int>&nums,int res){
        int n = nums.size();
        if(i == n){
            // cout<<res<<"\n";
            if(res>val){
                val = res;
                ans = 1;
            }
            else if(res == val){
                ans++;
            }
            return;
        }
        // not take
        helper(i+1,nums,res);
        
        // take
        helper(i+1,nums,res|nums[i]);
        
    }
    int countMaxOrSubsets(vector<int>& nums) {
        helper(0,nums,0);
        return ans;
    }
};

