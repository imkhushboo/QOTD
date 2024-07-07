class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        
        int ans = 0;
        int rem = 0;
        int filledbottles = numBottles;
        int emptybottles = 0;
        while(filledbottles>0)
        {
            // cout<<filledbottles<<" ";
            // drink filled bottles;
            ans += filledbottles;
            
            // new empty bottles;
            emptybottles += filledbottles;
            
            // exchange
            filledbottles = emptybottles/numExchange;
            
            emptybottles = emptybottles%numExchange;
        }
        
        return ans;
        
    }
};
