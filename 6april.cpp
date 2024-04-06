class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        int cnt = 0;
        int n = s.size();
        string ans = "";
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                cnt++;
                ans += s[i];
            }
            else if (s[i] == ')')
            {
                if (cnt > 0)
                {
                    ans += s[i];
                    cnt -= 1;
                }
            }
            else
            {
                ans += s[i];
            }
        }
        int temp = 0;
        int m = ans.size();
        string nans = "";
        for (int i = m - 1; i >= 0; i--)
        {
            if (ans[i] == ')')
            {
                temp++;
                nans += ans[i];
            }
            else if (ans[i] == '(')
            {
                if (temp > 0)
                {
                    temp--;
                    nans += ans[i];
                }
            }
            else
            {
                nans += ans[i];
            }
        }

        reverse(nans.begin(), nans.end());
        return nans;
    }
};