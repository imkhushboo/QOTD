class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int cnt=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]) cnt++;
        }
        int i=0,j=0,zero=0;
        int ans=2*n;
        while(j<2*n)
        {
            if(nums[j%n]==0)
            {
                zero++;
            }
            if(j-i+1==cnt)
            {
                ans=min(ans,zero);
                if(nums[i%n]==0)
                {
                    zero--;
                }
                i++;
            }
            j++;
        }
        if(ans==2*n) return 0;
        return ans;
    }
};
