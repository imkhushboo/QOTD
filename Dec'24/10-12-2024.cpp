class Solution {
public:
    int maximumLength(string s) {
       int n = s.size();
        int ans = -1;
        for(int k = 1;k<=n;k++){
            map<string,int>mp;
            int cnt = 0;
            for(int i=0;i<=n-k;i++)
            {
                string st = s.substr(i,k);
                bool flag = true;
                for(auto x:st){
                    if(x !=s[i]){
                        flag = false;
                        break;
                    }
                }
                
                if(flag == true){
                    mp[st]++;
                cnt = max(cnt,mp[st]);
                }
                
                
            }
            
            if(cnt>=3){
                ans = k;
            }
        }
        
        return ans;
        
    }
};
