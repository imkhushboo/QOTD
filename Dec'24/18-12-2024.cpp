class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
       int n=prices.size();
        vector<int>fin_vp(n,0);
       for(int i=0;i<n;i++)
       {
           int fin=prices[i];
           for(int j=i+1;j<n;j++)
           {
               if(prices[j]<=prices[i])
               {
                   fin-=prices[j];
                   break;
               }
           }
           fin_vp[i]=fin;
       }
        return fin_vp;
    }
};
