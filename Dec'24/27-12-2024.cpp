class Solution {
public:
//     int f(int i,values){
//         int n=values.size();
//         if(i>n){
//             return -1e9;
//         }
//         int maxi=-1e9;
//         for(int j=i+1;j<n;j++){
//             maxi=max(maxi,f(j,values));
//         }
//         return maxi+values[i]+i;
        
        
        
        
//     }
    
    
    
    
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
          vector<int>v(n);
        int cur=INT_MIN;
        v[n-1]=0;
        for(int i=n-2;i>=0;i--){
            v[i]=max(cur,values[i+1]-(i+1));
            cur=max(cur,v[i]);
            // cout<<cur<<"--\n";
        }
        for(auto x:v) cout<<x<<" ";
        // cout<<"\n";
        int ans=INT_MIN;
        for(int i=0;i<n-1;i++){
            ans=max(ans,values[i]+i+v[i]);
        }
        return ans;
    }
};
