class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        int i =0 ,j =0;
        sort(s1.begin(),s1.end());
        while(j<m){
            if(j-i+1 == n){
                string str = s2.substr(i,j-i+1);
                
                sort(str.begin(),str.end());
                if(str == s1) return true;
                else{
                    i++;
                }
            
            }
            j++;
        }
        return false;
    }
};
