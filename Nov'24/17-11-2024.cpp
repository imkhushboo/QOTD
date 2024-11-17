// #include<bits/stdc++.h>
#define ll long long 
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
        int n=nums.size();
        ll j=0,sum=0,ans=LONG_MAX;
        while(j<n)
        {
           sum+=nums[j];
            if(sum>=k)
            {
                ans=min(ans,j+1);
            }
            while(!pq.empty() and sum-pq.top().first>=k)
            {
                ans=min(ans,j-pq.top().second);
                pq.pop();
            }
            pq.push(make_pair(sum,j));
            j++;
        }
        if(ans==INT_MAX) return -1;
        return ans;
         
    }
};
