class Solution {
public:
    int minLength(string s) {
        
        while(s.find("AB")<s.size() or s.find("CD") <s.size()){
            
            if(s.find("AB")<s.size()){
                int ind = s.find("AB");
                s.erase(ind,2);
            }
            
            if(s.find("CD")<s.size() ){
                int ind = s.find("CD");
                s.erase(ind,2);
            }
        }
        
        return s.size();
        
    }
};
