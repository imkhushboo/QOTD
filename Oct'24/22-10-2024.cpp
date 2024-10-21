class Solution {
public:
    int helper(int i,int j,string s,vector<string>&vec){
        int n = s.size();
        if(j == n){
            return vec.size();
        }
        
        
        // not split
        int ans  = helper(i,j+1,s,vec);
        
        // split
        string str = s.substr(i,j-i+1);
        if(find(vec.begin(),vec.end(),str) == vec.end()){
            vec.push_back(str);
            ans = max(ans,helper(j+1,j+1,s,vec));
            vec.pop_back();
        }
        return ans;
        
    }
    int maxUniqueSplit(string s) {
        vector<string>vec;
        return helper(0,0,s,vec);
    }
};
