class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0;
        int n = str1.size();
        for(auto x:str2){
            bool flag = false;
            // cout<<i<<"\n";
           while(i<n){
               char y = str1[i];
                if(x == y or(y == 'z' and x == 'a') or (x-y == 1)) {
                    i++;
                    flag = true;break;
               
           }
             i++;   
            }
            if(flag == false) return false;
        }
        
        return true;
        
    }
};
