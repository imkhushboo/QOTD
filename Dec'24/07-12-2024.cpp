class Solution {
public:
    
    int helper(vector<int>&nums,int maxi)
    {
        int opr = 0;
        
        for(auto x:nums){
            
            opr+=(x/maxi);
            
            if(x%maxi == 0) opr--;
            
            
        }
        // cout<<opr<<" "<<maxi<<"\n";
        return opr;
    }
    
    
    int minimumSize(vector<int>& nums, int maxOperations) {
       int ans = -1;
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        while(low<=high)
        {
            
            // cout<<low<<" "<<high<<"\n";
            int mid = low + (high-low)/2;
            
            
            if(helper(nums,mid) <=maxOperations){
               ans = mid;
                high = mid-1;
            }
            else{
                
               low = mid+1;
            }
            
            
        }
        
        return ans;
        
    }
};




