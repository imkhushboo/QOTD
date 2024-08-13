class Solution {
public:
     void helper(int i,vector<int>& candidates,int target,vector<int>temp,vector<vector<int>>&ans)
    {
        int n =  candidates.size();
        // cout<<i<<"\n";
        if(i == n)
        {
            if(target  == 0 )
            {
               ans.push_back(temp);
               
            }
            
            return;
        }
         
         if(target == 0) ans.push_back(temp);
        
         for(int j=i;j<n;j++)
         {
             if(i == j or candidates[j] != candidates[j-1] && candidates[j] <= target)
             {
                 temp.push_back(candidates[j]);
                 helper(j+1,candidates,target-candidates[j],temp,ans);
                 temp.pop_back();
             }
         }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        
        vector<int>temp;
        
        helper(0, candidates,target,temp,ans);
        
        return ans;
    
        
    }
};
