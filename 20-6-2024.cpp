class Solution {
public:
    int helper(int mid , vector<int>&position)
    {
        int n = position.size();
        int cnt = 0;
        int last = position[0];
        for(int i=1;i<n;i++)
        {
            if(position[i] - last >= mid)
            {
                cnt++;
                last = position[i];
            }
        }
        // cout<<mid<<" "<<cnt<<"\n";
        return cnt+1;
    }
    
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n = position.size();
        int start = 1, end = position[n-1] - position[0];
        int ans = -1;
        while(start<=end)
        {
            int mid = start + (end - start)/2;
            
            
            if(helper(mid,position)<m)
            {
                end = mid-1;
                
            }
            else{
                ans = mid;
                start = mid+1;
            }
        }
        return ans;
    }
};
