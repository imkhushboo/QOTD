class Solution {
public:
    
    int helperx(string &s, int x)
    {
        // cout<<s<<" ";
        stack<char>st;
        int ans = 0;
        for(auto it: s)
        {
            // cout<<it<<"--\n";
            if(!st.empty() and st.top() == 'a' and it == 'b')
            {
                st.pop();
                ans += x;
            }
            else{
                st.push(it);
            }
        }
        s = "";
         while(!st.empty())
         {
             s += st.top();
             st.pop();
         }
         
         reverse(s.begin(),s.end());
        // cout<<s<<" \n";
        return ans;
    }
    
     int helpery(string &s, int y)
    {
        stack<char>st;
         // cout<<s<<" ";
        int ans = 0;
        for(auto it: s)
        {
            if(!st.empty() and st.top() == 'b' and it == 'a')
            {
                st.pop();
                ans += y;
            }
            else{
                st.push(it);
            }
        }
        s = "";
         while(!st.empty())
         {
             s += st.top();
             st.pop();
         }
         
         reverse(s.begin(),s.end());
         // cout<<s<<" \n";
        return ans;
    }
    
    
    int maximumGain(string s, int x, int y) {
        int ans = 0;
        if(x>y)
        {
            ans = helperx(s,x) + helpery(s,y);
        }
        else{
            ans = helpery(s,y) + helperx(s,x);
        }
        
        return ans;
        
    }
};

