class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int i = 0, j = 0;
        int n = nums.size();
        priority_queue<pair<int,int>>pq_maxi;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq_mini;
        int ans = 0;
        
        while(j<n)
        {
            pq_maxi.push({nums[j],j});
            pq_mini.push({nums[j],j});
            
            int top_maxi = pq_maxi.top().first;
            int ind_maxi = pq_maxi.top().second;
            
            int top_mini = pq_mini.top().first;
            int ind_mini = pq_mini.top().second;
            
            // cout<<j<<"\n";
            if(abs(top_maxi-top_mini) <= limit)
            {
                ans = max(ans,j-i+1);
            }
            else{
                
                while(!pq_maxi.empty() and pq_maxi.top().second <=i)
                {
                    // cout<<"-\n";
                    pq_maxi.pop();
                }
                
                while(!pq_mini.empty() and pq_mini.top().second <= i)
                {
                    // cout<<"--\n";
                    pq_mini.pop();
                }
                i++;
            }
            j++;
            
        }
        
        return ans;
        
        // 10 1 2 4 7 2
        
        
    }
};
