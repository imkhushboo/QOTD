class Solution {
private:
    int findTotalLandCount(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>vis(n, vector<bool>(m, false));
        int count = 0;
        
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                if (grid[i][j] == 1 and !vis[i][j])
                {
                    queue<pair<int, int>>q;
                    q.push({i, j});
                    count += 1;
                    vis[i][j] = true;
                    
                    while(!q.empty())
                    {
                        int row = q.front().first;
                        int col = q.front().second;
                        q.pop();
                        
                        for (int i=0;i<4;i++)
                        {
                            int nrow = row + dx[i];
                            int ncol = col + dy[i];
                            if (nrow >=0 and nrow < n and ncol >= 0 and ncol < m and !vis[nrow][ncol] and grid[nrow][ncol] == 1)
                            {
                                vis[nrow][ncol] = true;
                                q.push({nrow, ncol});
                            }
                        }
                    }
                }
            }
        }
        
        return count;
    }
public:
    int minDays(vector<vector<int>>& grid) 
    {
        int land = findTotalLandCount(grid);
        if (land == 0 or land >= 2)   return 0;
        int n = grid.size();
        int m = grid[0].size();
        
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                if (grid[i][j] == 1)
                {
                    grid[i][j] = 0;
                    int land = findTotalLandCount(grid);
                    if (land != 1)   return 1;
                    grid[i][j] = 1;
                }
            }
        }
        
        return 2;
    }
};


// [[1,1,0,1,1],
//  [1,1,1,1,1],
//  [1,1,0,1,1],
//  [1,1,0,1,1]]
