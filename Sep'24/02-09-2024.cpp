class Solution {
public:
    
 
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        long long sum = 0;
        for(auto x:chalk)
        {
            sum += x;
        }
        k%=sum;
        for(int i=0;i<n;i++)
        {
            
            k-=chalk[i];
            if(k<0) return i;
        }
        
        return -1;
        
        
    }
};
