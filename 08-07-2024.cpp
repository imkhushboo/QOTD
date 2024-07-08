class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int>vp(n);
        for(int i=1;i<=n;i++) vp[i-1] = i;
        
        int ind = 0;
        while(vp.size()>1)
        {
            int next = (ind + k-1)%n;
            
            // cout<<next<<"\n";
            vp.erase(vp.begin()+next);
            ind = next;
            n--;
        }
        return vp[0];
    }
};
