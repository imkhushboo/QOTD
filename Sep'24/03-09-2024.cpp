class Solution {
public:
    int getLucky(string s, int k) {
        map<char,int>mp;
        
        for(int i=0;i<26;i++)
        {
            mp[i+'a']=i+1;
        }
        string st ="";
        for(auto x: s)
        {
            st+=to_string(mp[x]);
        }
        int sum = 0;
        
        while(k--)
        {
          sum = 0;
          for(auto x:st)
          {
              sum += x-'0';
          }
            st = to_string(sum);
        
        }
        
        return sum;
        
        
    }
};
