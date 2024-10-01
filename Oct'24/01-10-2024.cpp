class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int>arr2(k,0);
        int n = arr.size();
        for(int i=0;i<n;i++){
            arr2[((arr[i]%k)+k)%k]++;
        }
        
        int total = 0;
        for(int i=1;i<=k/2;i++){
            if(arr2[i] != arr2[k-i]) return false;
            total += arr2[i];
        }
        
        if(arr2[0]%2 !=0) return false;
        total += arr2[0]/2;
        
        if(k%2 == 0 and arr2[k/2]%2 !=0) return false;
        return true;
        
    }
};
