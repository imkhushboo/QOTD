class Solution {
public:
    string reverseParentheses(string s) 
    {
        stack<char>st;
        
        for (int i=0;i<s.size();i++)
        {
            if (s[i] == '(')
            {
                st.push('*');
            }
            else if (s[i] == ')')
            {
                string ans ="";
                while(!st.empty() and st.top() != '*')
                {
                    ans += st.top();
                    st.pop();
                }
                //cout<<"ans"<<" "<<ans<<endl;
                st.pop();
                for (int i=0;i<ans.size();i++)   st.push(ans[i]);
            }
            else   st.push(s[i]);
        }
        
        string og = "";
        while(!st.empty())
        {
            og += st.top();
            st.pop();
        }
        
        reverse(og.begin(), og.end());
        return og;
    }
};
