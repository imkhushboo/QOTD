class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        stack<pair<int,pair<pair<int,char>,int>>>st;
        vector<pair<int,pair<pair<int,char>,int>>>vp;
        int n = positions.size();
        for(int i=0;i<n;i++)
        {
            vp.push_back({positions[i],{{healths[i],directions[i]},i}});
        }
        
        sort(vp.begin(),vp.end());
        
        for(auto x:vp)
        {
            pair<int,pair<pair<int,char>,int>> val = x;
            // cout<<val.first<<"\n";
            int flag = 0;
           while(val.second.first.second == 'L' and !st.empty() and st.top().second.first.second == 'R')
           {
                   pair<int,pair<pair<int,char>,int>> topp = st.top();
                   int health1 = st.top().second.first.first;
                   int health2 = val.second.first.first;
               // cout<<health1<<" "<<health2<<"\n";
                   st.pop();
                   if(health1 > health2) 
                   {
                      val = topp;
                      val.second.first.first--;
                   }
                   else if(health2> health1)
                   {
                       val.second.first.first--;
                   }
                   else{
                       flag = 1;
                       break;
                   }
           }
            if(flag == 0)
            st.push(val);
        }
        
        vector<pair<int,int>>ans;
        
        while(!st.empty())
        {
            // cout<<st.top().first<<" \n";
            ans.push_back({st.top().second.second,st.top().second.first.first});
            st.pop();
        }
        sort(ans.begin(),ans.end());
        
        vector<int>final_ans;
        for(auto x: ans)
        {
            final_ans.push_back(x.second);
        }
        
        return final_ans;
    }
};
