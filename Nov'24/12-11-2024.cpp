class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(),items.end());
        vector<int>price,beauty;
        int n = items.size();
        price.push_back(items[0][0]);
        beauty.push_back(items[0][1]);
        for(int i=1;i<n;i++){
            int m = price.size();
            if(price[m-1] == items[i][0]){
                beauty[m-1] = max(beauty[m-1],items[i][1]);
            }
            else{
               price.push_back(items[i][0]);
               beauty.push_back(max(items[i][1],beauty[m-1])); 
            }
            
        }
        
        
        
        vector<int>ans;
        
        
        for(auto x:queries){
            int ind = lower_bound(price.begin(),price.end(),x) -price.begin();
            // cout<<ind<<"\n";
            if(ind == price.size()) ans.push_back(beauty[price.size()-1]);
            else if(price[ind] == x) ans.push_back(beauty[ind]);
            else if(ind - 1 == -1) ans.push_back(0);
            else ans.push_back(beauty[ind-1]);
        }
        
        return ans;
        
        
    }
};
