class Solution {
public:
    
    bool helper(vector<string>&s1,vector<string>&s2){
        int n = s1.size();
        int m = s2.size();
        int i1 = 0 , j1 = n-1;
        int i2 = 0 , j2 = m-1;
        
        while(i1<=j1 and i2<=j2){
                        
            if(s1[i1] != s2[i2] and s1[j1] != s2[j2]) break;
            
            if(s1[i1] == s2[i2]) {
                i1++;
                i2++;
            }
            
            if(s1[j1] == s2[j2]){
                j1--;
                j2--;
            }
            

        }
       
        if(i2>j2) return true;
        return false;
        
    }
    
    
    bool areSentencesSimilar(string sentence1, string sentence2) {
        
        if(sentence1 == sentence2) return true;
        vector<string>s1,s2;
        string str1,str2;
        stringstream  ss1(sentence1);
        
        while(getline(ss1,str1,' ')){
            s1.push_back(str1);
        }
        
        
        stringstream ss2(sentence2);
        
        while(getline(ss2,str2,' ')){
            s2.push_back(str2);
        }
        
        int n = s1.size();
        int m = s2.size();
        
        if(n<m) return helper(s2,s1);
        
        return helper(s1,s2);
        
        
    }
};
