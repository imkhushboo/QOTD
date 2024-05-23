class Solution {

private:
    
    
    bool isValidSubset(vector<int>&x,int k)
    {
        int n = x.size();
        int flag = 0;
        for(int i=0;i<n;i++)
        {
            // cout<<x[i]<<" ";
            for(int j=i+1;j<n;j++)
            {
                if(x[j] - x[i] == k)
                {
                    flag = 1;
                    break;
                }
            }
        }
        // cout<<"\n";
            
          return flag == 0;
    }
    
    int helper(int i,vector<int>&nums,int k,vector<int>&vec)
    {
        int n = nums.size();
        
        if(i == n){
            if(!vec.empty())
            {
                return isValidSubset(vec,k);
            }
            return 0;
        }
        
        //logic
        
        int ans = 0;
        //not take
        ans += helper(i+1,nums,k,vec);
        
        //take
        vec.push_back(nums[i]);
        ans += helper(i+1,nums,k,vec);
        vec.pop_back();
        
        return ans;
        
    }
    
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        
        vector<int>vec;
       
        
        return helper(0,nums,k,vec);  
        
    }
};

