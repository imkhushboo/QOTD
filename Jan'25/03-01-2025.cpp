class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long int end=0,start=0;
        for(auto x:nums)
        {
            end+=x;
        }
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n-1;i++)
        {
            start+=nums[i];
            end-=nums[i];
            
            if(start>=end)
            {
                cnt++;
            }
            
        }
        return cnt;
        
    }
};
