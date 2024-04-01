class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int n = s.size();
        string st = "";
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] != ' ')
            {
                st += s[i];
            }
            else if (st != "")
            {
                return st.size();
            }
        }

        return st.size();
    }
};