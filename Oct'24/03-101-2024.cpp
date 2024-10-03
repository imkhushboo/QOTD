class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long summ = 0;
        vector<long long>pre(n,0);
        pre[0] = nums[0];
        for(int i=1;i<n;i++){
            pre[i] = pre[i-1] + nums[i];
        }
        
        summ = pre[n-1];
        
        if(summ % p == 0) return 0;
        int len = n;
       for(int i = 1;i<n;i++)
       {
           for(int j=i-1;j<n;j++){
               long long val = 0;
               if(i == 1){
                   val = nums[j];
               }
               else if(j-i+1 == 0){
                   val = pre[j];
               }
               else
               val = pre[j] - pre[j-i];
               // cout<<val<<"\n";
               if((summ - val)%p == 0) return i;
               
           }
       } 
        
        return -1;
    }
};
