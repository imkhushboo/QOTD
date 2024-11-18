class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int>ans(n,0);
        
        for(int i=0;i<n;i++){
            if(k == 0){
                ans[i] = 0;
            }
            else if(k > 0){
                int j = 1;
                while(j <= k){
                    ans[i] += code[(i+j)%n];
                    j++;
                }
            }
            else{
                int j = 1;
                
                while(j<=abs(k)){
                    ans[i] += code[(i-j+n)%n];
                    j++;
                }
            }
        }
        
        return ans;
        
    }
};
