class Solution {

public:
    int numSteps(string s) {
        // cout<<s<<"\n";
        int n = s.size();
       if(n == 1)
       {
           return 0;
       }
        
        if(s[n-1] == '1')
        {
            int i = n-2;
            s[n-1] = '0';
            while(i>=0 and s[i] == '1')
            {
                s[i] = '0';
               i--; 
            }
            if(i>=0) s[i] = '1';
            else s = '1'+ s;
            
            return 1 + numSteps(s);
        }
        string st = s.substr(0,n-1);
        return 1 + numSteps(st);
        
    }
};

