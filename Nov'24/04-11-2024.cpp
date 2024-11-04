class Solution {
public:
    string compressedString(string word) {
        string ans = "";
        int n = word.size();
        int cnt = 1;
       
        for(int i=1;i<n;i++){
            if(word[i] == word[i-1]){
               
                cnt++;
            }
            else{
                if(cnt == 0){
                    cnt = 1;
                } 
                else{
                     ans+=to_string(cnt);
                    ans+=word[i-1];
                    cnt = 1;
                }
               
            }
            if(cnt == 9){
                ans+=to_string(cnt);
                ans+=word[i-1];
                cnt = 0;
            }
            
        }
        if(cnt != 0){
          ans+=to_string(cnt);
        ans+=word[n-1];    
        }
        
        
        
        return ans;
        
        
    }
};
