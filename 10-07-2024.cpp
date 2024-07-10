class Solution {
public:
    int minOperations(vector<string>& logs) {
        int opr = 0;
        
        for(auto x:logs)
        {
            if(x == "../" ) opr= max(0,opr-1);
            else if(x == "./") continue;
            else opr++;
        }
        return opr;
        
    }
};
