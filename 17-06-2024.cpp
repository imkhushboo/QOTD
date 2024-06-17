class Solution {
public:
    bool judgeSquareSum(int c) {
        int start = 0, end = sqrt(c);
        
        while(start<=end)
        {
            
            if((long long)((long long)start*start + (long long)end * end) == c)
            {
                return true;
            }
            else if((long long)((long long)start*start +(long long) end * end) > c)
            {
                end--;
            }
            else{
                start++;
            }
        }
        
        return false;
    }
};
