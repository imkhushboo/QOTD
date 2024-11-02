class Solution {
public:
    bool isCircularSentence(string s) {
        vector<string>vt;
        stringstream ss(s);
        string word;
        while (ss >> word) {
           vt.push_back(word);
        }
        
        int n = vt.size();
        for(int i=0;i<n;i++){
            int m = vt[i].size();
            if(vt[i][m-1] != vt[(i+1)%n][0]) return false;
        }
        
        return true;
    }
};
