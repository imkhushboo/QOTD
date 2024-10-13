class Solution {
public:

    int minGroups(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end());
        priority_queue<int,vector<int>,greater<int>>pq;
        
        
        for(auto x:intervals){
            
            if(!pq.empty() and pq.top()<x[0]){
                pq.pop();
            }
            
            pq.push(x[1]);
            
        }
        
        return pq.size();
        
        
    }
    
    
};


