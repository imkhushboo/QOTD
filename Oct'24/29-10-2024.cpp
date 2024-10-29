class Solution {
public:
    int dp[1001][1001];
    int helper(int val , int i,int j,vector<vector<int>>&grid){
        int n = grid.size();
        int m = grid[0].size();
        
        if(dp[i][j] != -1) return dp[i][j];

        if(j ==  m-1) return 0;
        int ans = 0;
      
        for(int k = -1;k<=1;k++){
            if(i-k>=0 and i-k<n and j+1<m and grid[i-k][j+1]>grid[i][j])
            ans = max(ans, 1 + helper(grid[i][j],i-k,j+1,grid));
        }
        
        return dp[i][j] = ans;
        
    }
    int maxMoves(vector<vector<int>>& grid) {
         int n = grid.size();
        int m = grid[0].size(); 
        memset(dp,-1,sizeof(dp));
        int fin_ans = 0;
        for(int i=0;i<n;i++){
            fin_ans = max(fin_ans,helper(-1,i,0,grid));  
        }
        
        return fin_ans;
    }
};
