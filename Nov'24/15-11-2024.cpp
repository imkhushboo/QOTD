class Solution {
public:
    int helper(int lin , int rin , vector<int>&arr)
        
    {
        int n = arr.size();
        
        if(lin < 0 && rin >=n)
        {
            return n-1;
        }
        else if(lin<0)
        {
            return rin;
        }
        else if(rin>=n)
        {
            return n-lin-1;
        }
        else if(lin>=rin)
        {
            return 0;
        }
        
        else if(arr[lin] <= arr[rin])
        {
            return rin-lin-1;
        }
        
      

        return min(helper(lin-1,rin,arr),helper(lin,rin+1,arr));
        
        
    }
    
    
    
    
    
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int leftind =0;
        int rightind = n-1;
        
        for(int i=1;i<n;i++)
        {
            if(arr[i] >= arr[i-1])
            {
                leftind = i;
            }
            else{
                break;
            }
        }
        
        for(int i=n-2;i>=0;i--)
        {
            if(arr[i]<= arr[i+1])
            {
                rightind = i;
            }
            else{
                break;
            }
        }
       
        
        int ans = helper(leftind,rightind,arr);
        return ans;
        
        
    }
};
