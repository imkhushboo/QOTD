class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        int teams = n/2;
        int summ = 0;
        for(int i=0;i<n;i++){
            summ += skill[i];
        }
        
        if(summ%teams != 0) return -1;
        
        int val = summ/teams;
        long long ans = 0;
       sort(skill.begin(),skill.end());
        int i = 0;
        int j = n-1;
        while(i<j){
            if(skill[i] + skill[j] == val){
                ans += skill[i]* skill[j];
            }
            else{
                return -1;
            }
            
            
            i++;
            j--;
        }
        
        return ans;
        
    }
};
