class Solution
{
public:
    int minimumLength(string s)
    {
        int n = s.size();

        int i = 0, j = n - 1;

        while (i < j)
        {

            if (s[i] == s[j])
            {
                while (i < j && s[i] == s[i + 1])
                {
                    i++;
                }

                while (j > i && s[j] == s[j - 1])
                {
                    j--;
                }
                i++;
                j--;
            }
            else
            {
                break;
            }
        }

        return i > j ? 0 : j - i + 1;
    }
};