class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int maxValue = -1;
        
        int chunks = 0;
        for(int i=0;i<n;i++)
        {
            maxValue = max(maxValue,arr[i]);
            
            if(maxValue == i)
            {
                chunks++;
            }
        }
        
        
        return chunks;
    }
};
