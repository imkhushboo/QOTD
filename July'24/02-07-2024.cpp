class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        map<int,int>mp1;
        map<int,int>mp2;
        for(int i=0;i<nums1.size();i++){
            mp1[nums1[i]]++;
        } 
         for(int i=0;i<nums2.size();i++){
            mp2[nums2[i]]++;
        }
        for( auto x: mp1){
            if(mp2.count(x.first)){
                int c=min(x.second,mp2[x.first]);
                while(c--)
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};
