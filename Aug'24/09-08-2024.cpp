class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        for(int i=0;i<=n-3;i++)
        {
            for(int j=0;j<=m-3;j++)
            {
                vector<int>vt(10,0);
                for(int k=i;k<i+3;k++)
                {
                    for(int l = j;l<j+3;l++)
                    {
                        // cout<<grid[k][l]<<" ";
                        if(grid[k][l] >=1 and grid[k][l] <= 9)
                        vt[grid[k][l]]++;
                    }
                }
                
                bool flag = false;
                
                for(int i=1;i<=9;i++)
                {
                    if(vt[i] != 1)
                    {
                        flag = true;break;
                    }
                }
                
                // col
                int cols = 0;
                int val = 0;
                
                for(int k=i;k<i+3;k++)
                {
                    cols = 0;
                    for(int l = j;l<j+3;l++)
                    {
                        cols += grid[k][l];
                    }
                    if(k == i)
                    val = cols;
                    else if(val != cols)
                    {
                        flag = true;
                        break;
                    }
                }
                
                // row
                int rows = 0;
                for(int l=j;l<j+3;l++)
                {
                    rows = 0;
                    for(int k = i;k<i+3;k++)
                    {
                        rows += grid[k][l];
                    }
                    if(l == j)
                    val = rows;
                    else if(val != rows)
                    {
                        flag = true;
                        break;
                    }
                }
                
                int dig1 = 0,dig2 = 0;
                int a = j;
                for(int k=i;k<i+3;k++)
                {
                    dig1 += grid[k][a++];
                }
                a = j;
                for(int k=i+2;k>=i;k--)
                {
                    dig2 += grid[k][a++];
                }
                
                if(dig1 != dig2)
                {
                    flag = true;
                }
                
                
                
                if(flag == false) cnt++;
                
                
            }
        }
        return cnt;
        
    }
};
