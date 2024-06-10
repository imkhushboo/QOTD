class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n = heights.size();
        vector<int>nheights(n,0);
        
        for(int i=0;i<n;i++)
        {
            nheights[i] = heights[i];
        }
        
        sort(nheights.begin(),nheights.end());
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(heights[i]  != nheights[i])
            {
                ans++;
            }
        }
        
        return ans;
    }
};
