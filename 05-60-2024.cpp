class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
       int n=words.size();
       vector<vector<int>>vt(n,vector<int>(26,0));
        for(int i=0;i<n;i++)
        {
            for(auto x:words[i]){
                vt[i][x-'a']++;
            }
        }
        vector<int>nvp(26,101);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<26;j++)
            {
                nvp[j]=min(nvp[j],vt[i][j]);
            }
        }
        vector<string>ans;
        for(int i=0;i<26;i++){
            while(nvp[i]){
                string s="";
               char val=(char)(i+'a');
               s+=val;
                ans.push_back(s);
                nvp[i]--;
            }
        }
        return ans;
    }
};
