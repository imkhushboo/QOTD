class Solution
{
public:
    int dp[101][101];
    bool helper(int i, string s, int cnt)
    {
        int n = s.size();
        if (cnt < 0)
            return false;

        if (i == n)
        {
            return cnt == 0;
        }

        if (dp[i][cnt] != -1)
            return dp[i][cnt];

        bool ans = false;
        if (s[i] == '(')
        {
            ans = ans or helper(i + 1, s, cnt + 1);
        }
        else if (s[i] == ')')
        {
            ans = ans or helper(i + 1, s, cnt - 1);
        }
        else
        {
            ans = ans or helper(i + 1, s, cnt + 1);
            ans = ans or helper(i + 1, s, cnt - 1);
            ans = ans or helper(i + 1, s, cnt);
        }

        return dp[i][cnt] = ans;
    }
    bool checkValidString(string s)
    {
        memset(dp, -1, sizeof(dp));
        return helper(0, s, 0);
    }
};