class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans = 0;
        
        
        for(auto x: words)
        {
            int flag = 0;
            for(auto y:x)
            {
                if(find(allowed.begin(),allowed.end(),y) == allowed.end())
                {
                    flag = 1;
                    break;
                }
            
            }
            
            if(flag == 0) ans++;
        }
        
        return ans;
    }
};
