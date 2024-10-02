class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>marr;
        marr=arr;
        sort(marr.begin(),marr.end());
        int n=arr.size();
        vector<int>ans(n,0);
        map<int,int>mp;
        int cnt=1;
        for(auto x:marr)
        {
            if(!mp.count(x))
            {
                mp[x]=cnt;
                cnt++;
            }
        }
        for(int i=0;i<n;i++)
        {
            ans[i]=mp[arr[i]];
        }
        return ans;
    }
};
