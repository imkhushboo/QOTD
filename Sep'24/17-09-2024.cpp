class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        map<string,int>mp1,mp2;
        
         stringstream ss(s1);
         string word;
        while (ss >> word) {
            mp1[word]++;
        }
        
        stringstream ss2(s2);
        string word2;
        
        while(ss2>>word2)
        {
            mp2[word2]++;
        }
        
        vector<string>ans;
        for(auto x:mp1)
        {
            if(mp2.find(x.first) == mp2.end() and x.second == 1)
            {
                ans.push_back(x.first);
            }
        }
        
        for(auto x:mp2)
        {
            if(mp1.find(x.first) == mp1.end() and x.second == 1)
            {
                ans.push_back(x.first);
            }
        }
        
        return ans;
        
    }
};
