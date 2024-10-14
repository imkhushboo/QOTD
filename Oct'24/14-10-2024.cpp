class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>pq;
        
        for(auto x:nums){
            pq.push(x);
        }
        long long ans = 0;
        while(k--){
            ans += pq.top();
            int val = ceil((double)pq.top()/3.0);
            pq.pop();
            pq.push(val);
        }
        
        return ans;
        
    }
};
