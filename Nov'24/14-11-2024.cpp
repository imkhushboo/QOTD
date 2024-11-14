class Solution {
public:
    
    bool helper(int n , int maxi , vector<int>&quantities){
        long long val = 0;
        
        for(auto x: quantities){
            while(x){
                val++;
                if(x>=maxi){
                    x-=maxi;
                }
                else{
                    x = 0;
                }
                
            }   
            
        }  
        
        return val <= n;
    }
    
    
    int minimizedMaximum(int n, vector<int>& quantities) {
        
        long long summ = 0;
        
        for(auto x: quantities){
            summ += x;
        }
        
        
        if(summ <= n ) return 1;
        
        
        int low = summ/n;
        int high = *max_element(quantities.begin(),quantities.end());
        
        int ans = -1;
        
        while(low<=high){
            int mid = low + (high - low)/2;
            // cout<<mid<<"\n";
            
            if(helper(n,mid,quantities)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        
        return ans;
    }
};
