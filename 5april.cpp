class Solution
{
public:
    string makeGood(string s)
    {

        int n = s.size();
        stack<char> st;
        string ans = "";
        for (int i = 0; i < n; i++)
        {
            // cout<<"where\n";
            if (st.empty())
            {
                st.push(s[i]);
            }
            else
            {
                // cout<<"here\n";
                char ch = st.top();
                // cout<<ch<<"\n";
                if (ch - s[i] == 32 or s[i] - ch == 32)
                {
                    // cout<<"idhar\n";
                    st.pop();
                }
                else
                {
                    st.push(s[i]);
                }
            }
            // cout<<"--\n";
        }

        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};