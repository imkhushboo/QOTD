class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        ans += s[0];
        int cnt = 1;
        int n= s.size();
        for(int i=1;i<n;i++){
            if(s[i] == s[i-1] ){
                cnt++;
            }
            else{
                cnt = 1;
            }
            
            if(cnt<=2){
                ans+=s[i];
            }
        }
        
        return ans;
        
        
    }
};
