class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        for(int i=0;i<arr.size();i++)
        {
            
            if(find(arr.begin(),arr.end(),2*arr[i]) != arr.end())
            {
                int ind = find(arr.begin(),arr.end(),2*arr[i])-arr.begin();
                if(ind !=i) return true;
            }
        }
        
        return false;
        
    }
};
