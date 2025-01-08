class Solution {
public:

  bool isPrefixAndSuffix(string s1,string s2)
  {
    int n = s1.size();
    int m = s2.size();

    if(s2.substr(0,n) != s1 or s2.substr(m-n,m) != s1) return false;

    return true;

  }

    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(isPrefixAndSuffix(words[i],words[j])){
                   cnt++; 
                }
            }
        }

        return cnt;
    }
};
