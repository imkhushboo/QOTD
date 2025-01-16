class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int xorr1 = nums1[0];
        for(int i=1;i<n;i++){

            xorr1 ^= nums1[i];

        }
        int xorr2 = nums2[0];

        for(int i=1;i<m;i++){
            xorr2^= nums2[i];
        }

        if(m%2 == 0) xorr1 = 0;
        if(n%2 == 0) xorr2 = 0;

        return xorr1^xorr2;

    }
};
