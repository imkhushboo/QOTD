class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string>ans;

        unordered_map<char,int>map;

        for(auto x: words2){
            unordered_map<char,int>mp;
            for(auto y:x){
                mp[y]++;

            }

            for(auto it:mp){
                if(map.find(it.first) == map.end())
                {
                    map[it.first] = it.second;
                }
                else{
                    map[it.first] = max(it.second,map[it.first]);
                }
            }
        }

    //   for(auto x:map){
    //     cout<<x.first<<" "<<x.second<<"\n";
    //   }

        for(auto x:words1){
            unordered_map<char,int>mp1;
            for(auto y:x){
                mp1[y]++;
            }
            bool flag = true;
            for(auto it:map){

                if(mp1.find(it.first) == mp1.end() or mp1[it.first] < it.second)
                {
                    flag = false;
                    break;
                }
            }

            if(flag){
                ans.push_back(x);
            }
        }

        return ans;
    }
};
