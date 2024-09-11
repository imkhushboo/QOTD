class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xr = start^goal;
        int cnt = 0;
        for(int i = 0 ; i<32;i++)
        {
            long long val = pow(2,i);
            if((val & xr) == val)
            {
                cnt++;
            }
        }
        return cnt;
        
    }
};
