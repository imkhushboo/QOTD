class Solution {
public:
    int passThePillow(int n, int time) {
        int val = 1;
        int factor = -1;
        int num = 1;
        while(val<=time)
        {
            if(num%n == 0 or num%n == 1)
            {
                if(factor < 0) factor = 1;
                else factor = -1;
            }
            num += factor;
            val++;
            
            // cout<<num<<" ";
        }
        
        return num;
    }
};
