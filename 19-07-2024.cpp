class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int>mini(m,1e5),maxi(n);
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                mini[i] = min(mini[i],matrix[i][j]);
            }
        }
        
        for(int j=0;j<n;j++)
        {
            for(int i=0;i<m;i++)
            {
                maxi[j] = max(maxi[j],matrix[i][j]);
            }
        }
        
        vector<int>ans;
        
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mini[i] == matrix[i][j] and maxi[j] == matrix[i][j])
                {
                    ans.push_back(matrix[i][j]);
                }
            }
        }
        
        return ans;
    }
};
