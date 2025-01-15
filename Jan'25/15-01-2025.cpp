class Solution {
public:
    int minimizeXor(int num1, int num2) {

        int cntSetbits = 0;
       
        for(int i=0;i<32;i++){
            long int val =  pow(2,i);

            if(val & num2) cntSetbits++;
        }

        int ans = 0;

        for(int i=31;i>=0;i--)
        {
            long int val = pow(2,i);

            if(cntSetbits == 0) break;

            if(num1 & val){
                cntSetbits--;
                ans += val;

            }
        }


        for(int i=0;i<=31;i++){
            if(cntSetbits == 0) break;

            long int val = pow(2,i);

            if((val & num1) == 0){
                cntSetbits--;
                ans += val;
            }
        }

        return ans;


        
    }
};
