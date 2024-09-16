class Solution {
public:
    vector<int> helper(string s)
    {
        stringstream ss(s);
        string word;
        
        vector<int>ans;
        while (!ss.eof()) {
            getline(ss, word, ':');
            ans.push_back(stoi(word));
        }
        
        return ans;
    }

    
    int findMinDifference(vector<string>& timePoints) {
        // sort(timePoints.begin(),timePoints.end());
        int n = timePoints.size();
        int ans = 1e9;
        vector<int>vec;
        
        for(int i=0;i<n;i++)
        {
            int hrtomin = helper(timePoints[i])[0]*60;
            int min = helper(timePoints[i])[1];
            
            vec.push_back(hrtomin+min);
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j = i+1;j<n;j++)
            {
                int diff = abs(vec[i] - vec[j]);
                ans = min(ans,min(diff, 1440-diff));
            }
        }
        
        
        return ans;
        
        
    }
};
