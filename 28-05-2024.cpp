class Solution {

public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int ans = 0;
        
       int i=0,j=0;
        int sum = 0;
        while(j<n)
        {
            sum += abs(s[j]-t[j]);
            
            while(sum>maxCost)
            {
                sum -= abs(s[i]-t[i]);
                i++;
            }
            
            if(sum<= maxCost)
            {
                ans = max(ans,j-i+1);
            }
            j++;
        }
        
        return ans;
        
        
        
        
    }
};
