class Solution {
public:
    string invert(string s){
        for(int i=0;i<s.size();i++){
            if(s[i] == '0'){
                s[i] =  '1';
            }
            else{
                s[i] = '0';
            }
        }
        return s;
    }
    string helper(int n ){
        if(n == 0) return "0";
        
        string st = helper(n-1);
        string rst = invert(st);
        reverse(rst.begin(),rst.end());
        
        return st+"1"+rst;
    }
    char findKthBit(int n, int k) {
        
        return helper(n)[k-1];
        
    }
};
