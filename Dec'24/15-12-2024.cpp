class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        double ans = 0.0;
        int n = classes.size();
        // double mini = 1.0;
        // int ind = -1;
//         priority_queue<pair<double,int>>pq;
        
//         for(int i=0;i<n;i++){
            
//             double val = (double)classes[i][0]/(double)classes[i][1];
//             pq.push({val,i});
            
            
//         }
//         while(extraStudents--){
//             int ind = pq.top().second;
//             cout<<ind<<" ";
//             pq.pop();
            
//             double val = (double)(classes[ind][0] + 1)/((double)(classes[ind][1]+1)*(double)n);
//             pq.push({val,ind});
//         }
        
//         while(!pq.empty()){
//             ans += pq.top().first;
//             pq.pop();
//         }
        
        priority_queue<pair<double,int>>pq;
        
        for(int i=0;i<n;i++){
                double orig = (double)(classes[i][0])/(double)(classes[i][1] ) ;
                double neww = (double)(classes[i][0] + 1)/(double)(classes[i][1] + 1);
                
            
               pq.push({neww-orig,i});
                
            }
            
        
        while(extraStudents--){
            
            int ind = pq.top().second;
            pq.pop();
            
            classes[ind][0]++;
            classes[ind][1]++;
            
            double orig = (double)(classes[ind][0])/(double)(classes[ind][1] ) ;
            double neww = (double)(classes[ind][0] + 1)/(double)(classes[ind][1] + 1);
                
            
               pq.push({neww-orig,ind});
            
            
        }
        
        
        for(int i=0;i<n;i++){
            double val = (double)(classes[i][0])/(double)(classes[i][1] ) ;
            ans += val;
        }
        
        return ans/(double)n;
    }
};

