class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int>row(m,0),col(n,0);
        vector<pair<int,int>>vp(arr.size()+1);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                vp[mat[i][j]] = {i,j};
            }
        }
       

        for(int k=0;k<arr.size();k++){
            int i =vp[arr[k]].first;
            int j = vp[arr[k]].second;
            row[i]++;
            col[j]++;

            // cout<<row[i]<<" "<<col[j]<<"\n";

            if(row[i] == n) return k;
            if(col[j] == m) return k;

        }

        return -1;
    }
};
