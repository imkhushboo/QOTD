class Solution {
public:
 
    
    string shortestPalindrome(string s) {
        
        //kmp algorithm
        string kk=s;
        string h=s+'#';
        reverse(s.begin(),s.end());
        h+=s;
        
        int n=s.size();
        if(n==0) return kk;
        vector<int>lps(2*n+1,0);
        int len=0,i=1;
        while (i <= 2*n) {
            if (h[i]==h[len]) {
                len++;
                lps[i] = len;
                i++;
            }
            else 
            {
                if (len != 0) {
                    len = lps[len - 1];
                }
                else // if (len == 0)
                {
                    lps[i] = len;
                    i++;
                }
            }
        }
       // for(int i=0;i<2*n;i++)
       // {
       //     cout<<i<<": "<<lps[i]<<"\n";
       // }
        string gh=kk.substr(lps[2*n],n-lps[2*n]+1);
        reverse(gh.begin(),gh.end());
        return gh+kk;
        
        
    }
};
