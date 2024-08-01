class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        
        for(auto x: details)
        {
            string str = x.substr(11,2);
            int age = stoi(str);
            
            if(age > 60)
            {
                ans++;
            }
        }
        return ans;
        
    }
};
