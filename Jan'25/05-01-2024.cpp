class Solution {
private:
    char helpme(char x, int dir)
    {
        unordered_map<int, char>mp;
        for (int i = 0; i < 26; i++) 
        {
            mp[i] = 'a' + i;
        }

        int freq = x - 'a';
        if (dir < 0)
        {
            int reqFreq = (freq + dir + 26) % 26;
            return mp[reqFreq];
        }

        int reqFreq = (freq + dir) % 26;
        return mp[reqFreq];
    }
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) 
    {
        int n = s.size();
        vector<int>pre(n+1,0);

        for (int i=0;i<shifts.size();i++)
        {
            int start = shifts[i][0];
            int end = shifts[i][1];
            int dir = shifts[i][2] == 1 ? 1 : -1;

            pre[start] += dir;
            pre[end + 1] -= dir;
        }

        pre[0] = pre[0] % 26;

        for (int i=1;i<n;i++)  
        {
            pre[i] = (pre[i] + pre[i-1]) % 26;
        } 

        string ans = "";
        for (int i=0;i<s.size();i++)
        {
            char req = s[i];
            int direction = pre[i];
            if (direction == 0)
            {
                ans += req;
            }
            else
            {
                char temp = helpme(req, direction);
                ans += temp;
            }
        }
        return ans;
    }
};
