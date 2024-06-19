class Solution {
public:
    bool possible(int mid,int m,int k,vector<int>& bloomDay)
    {
        int cnt=0,ans=0;
        for(auto x:bloomDay)
        {
            if(x<=mid){
                cnt++;
            }
            else{
                ans+=cnt/k;
                cnt=0;
            }  
        }
        ans+=cnt/k;
        // cout<<cnt<<"\n";
        if(ans>=m) return true;
        return false;
        
        
    }
    
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;
        while(low<=high){
            
            int mid=low+(high-low)/2;
            
            if(possible(mid,m,k,bloomDay)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
            
            
        }
        return ans;
        
        
    }
};
