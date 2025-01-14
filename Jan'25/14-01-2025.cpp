class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int>mp;
        int n = A.size();
        vector<int>ans(n,0);

        for(int i=0;i<n;i++)
        {
            mp[A[i]]++;
            mp[B[i]]--;

            for(auto x:mp){
                if(x.second == 0){
                    ans[i]++;
                }
            }


           


        }

        return ans;
    }
};
