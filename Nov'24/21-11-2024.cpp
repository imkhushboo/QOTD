class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>v(m,vector<int>(n,0));
       for(auto x:guards){
           v[x[0]][x[1]]=-1;
       }
        for(auto x:walls){
            v[x[0]][x[1]]=1;
        }
        for(auto x:guards){
            int i=x[0],j=x[1];
                    //East{
                    for(int k=j+1;k<n;k++){
                        if(v[i][k]==1 || v[i][k]==-1) break;
                           v[i][k]=-2;
                    }
                    //West
                    for(int k=j-1;k>=0;k--){
                        if(v[i][k]==1 || v[i][k]==-1) break;
                        v[i][k]=-2;
                    }
                    //south
                    for(int k=i+1;k<m;k++){
                        if(v[k][j]==1 || v[k][j]==-1) break;
                        v[k][j]=-2;
                    }
                    //North
                    for(int k=i-1;k>=0;k--){
                        if(v[k][j]==1 || v[k][j]==-1) break;
                        v[k][j]=-2;
                    }
                 
                
            }
        int cnt=0;
           for(int i=0;i<m;i++){
               for(int j=0;j<n;j++){
                   // cout<<v[i][j]<<" ";
                   if(v[i][j]==0) cnt++;
               }
               // cout<<"\n";
           }
        return cnt;
    }
        
    
};
