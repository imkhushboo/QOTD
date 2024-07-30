class Solution {
public:
    int minimumDeletions(string s)
    {
        int countA = 0;
        int countB = 0;
        int ans = 0;
        
        for (int i=0;i<s.size();i++)
        {
            if (s[i] == 'a' and countB > 0)
            {
                ans += 1;
                countB -= 1;
            }
            else  if (s[i] == 'b')   countB += 1;
            else                     countA += 1;
        }
        
        return ans;
    }
};
