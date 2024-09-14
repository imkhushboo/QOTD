class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = 0;
        int m = rolls.size();
        for(auto x: rolls)
        {
            sum += x;
        }
        
        int ans = mean*(n+m) - sum;
        
        vector<int>arr(n,0);
        int val = ans/n;
        if(val <=0 or val >6) return {};
            
        for(int i=0;i<n;i++)
        {
            arr[i] += val;

        }
        ans = ans%n;
        // cout<<ans<<"\n";
        if( ans < n)
        {
            for(int i=0;i<ans;i++)
            {
                arr[i]++;
                
                if(arr[i] > 6 or arr[i]<=0) return {};
            }
        }
        
       
        
        return arr;
        
        
    }
};

