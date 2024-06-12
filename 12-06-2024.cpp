class Solution {
public:
    void sortColors(vector<int>& nums) {
//         int r=0,w=0,b=0;
//         for(int i=0;i<nums.size();i++)
//         {
//             if(nums[i]==0) r++;
//             else if(nums[i]==1) w++;
//             else b++;
//         }
//         int i=0;
//             while(r--)
//             {
//                 nums[i]=0;i++;
               
//             }
//             while(w--)
//             {
//                 nums[i]=1;i++;
               
//             }
//         while(b--)
//         {
//             nums[i]=2;
//             i++;
//         }
        
        
        //METHOD 2
//         DNF
        int low=0,high=nums.size()-1,mid=0;
        while(mid<=high)
        {
            if(nums[mid]==0)
            {
                swap(nums[low],nums[mid]);
                low++;mid++;
            }
            else if(nums[mid]==2)
            {
                swap(nums[mid],nums[high]);
                high--;
            }
            else{
                mid++;
            }
            
        }
        
    }
};
