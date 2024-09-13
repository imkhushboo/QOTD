class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        
        vector<int>xorr(n);
        
        xorr[0] = arr[0];
        
        for(int i=1;i<n;i++)
        {
            xorr[i] = xorr[i-1] ^arr[i];
        }
        
        vector<int>ans;
        
        for(auto x: queries)
        {
            int a = x[0];
            int b = x[1];
            
            if(a == 0)
            {
                ans.push_back(xorr[b]);
            }
            else{
               ans.push_back(xorr[b]^xorr[a-1]) ;
            }
                
            
        }
        return ans;
    }
};
