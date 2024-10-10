class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int>nge(n,0);
        nge[n-1] = nums[n-1];
        
        for(int i = n-2;i>=0;i--) nge[i] = max(nums[i],nge[i+1]);
        
        
        int i=0,j=0;
        int width = 0;
        while(j<n){
            if(nums[i]<=nge[j]){
            
            width = max(width,j-i);
            }
            while(i<n and nums[i]>nge[j]){
                i++;
            }
            j++;
        }
        return width;
        
    }
};
