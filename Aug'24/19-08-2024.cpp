class Solution {
public:
    
    int helper(int i,int curr,int n)
    {
        if(curr>n) return 1e9;
        if(curr == n) return 1;
        
        
        return min(1 + helper(i,curr+i,n),2+helper(curr,curr+curr,n));
    }
    int minSteps(int n) {
        if(n == 1) return 0;
        return helper(1,1,n);  
    }
};








