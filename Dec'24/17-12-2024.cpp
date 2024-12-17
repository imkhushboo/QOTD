class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
       vector<int>vt(26,0);
        
        for(auto x:s){
            vt[x-'a']++;
        }
        
        priority_queue<pair<char,int>>pq;
        string ans = "";
        for(int i=0;i<26;i++){
            if(vt[i]>0)
            pq.push({i+'a',vt[i]});
        }
        
        
        while(!pq.empty()){
            char topChar = pq.top().first;
            int topfreq = pq.top().second;
            
            pq.pop();
            int limit = repeatLimit;
            while(limit-- and topfreq--){
              ans += topChar;
            }
            
            if(topfreq >0 and pq.empty()) break;
            
            else if(topfreq > 0){
                char topChar2 =pq.top().first;
                int topfreq2 = pq.top().second;
                
                pq.pop();
                ans += topChar2;
                topfreq2--;
                // cout<<topChar2<<" "<<topfreq2<<"\n";
                if(topfreq2 >0){
                    pq.push({topChar2,topfreq2});
                }
                
                pq.push({topChar,topfreq});
            }
            
            
            
            
        }
        
        return ans;
    }
};
