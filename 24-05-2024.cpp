class Solution {
private:
    
    int helper(int i,vector<string>& words,map<char,int>&mp,vector<int>& score)
    {
        int n = words.size();
        if(i == n){
            return 0;
        }
        
        // not take
        
        int ans = helper(i+1,words,mp,score);
        
        // take
        
        bool flag = false;
        
        map<char,int>cmp;
        
        
        for(auto x: words[i])
        {
            cmp[x]++;
        }
        
        
        for(auto x: cmp)
        {
            if(mp.find(x.first) == mp.end() or mp[x.first] < x.second)
            {
                flag = true;
                break;
            }
        }
        int sum = 0;
        if(flag == false){
            for(auto x: words[i])
            {
                mp[x]--;
                if(mp[x] == 0)
                {
                    mp.erase(x);
                }
                sum += score[x-'a'];
                // cout<<x<<" ";
                
            }
            // cout<<"\n";
            
            ans = max(ans,sum + helper(i+1,words,mp,score));
            for(auto x: words[i])
            {
               mp[x]++;
                
            }
        }
        
        return ans;
    }
    
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        map<char,int>mp;
        
        for(auto x: letters)
        {
            mp[x]++;
        }
        
        return helper(0,words,mp,score);
        
    }
};
