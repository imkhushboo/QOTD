class Solution {
public:
    
    bool isupperCase(char ch)
    {
        return ch-'A' >=0 and ch-'A' <= 25;
    }
    
    bool islowerCase(char ch)
    {
        return ch-'a' >=0 and ch - 'a' <= 25;
    }
    
    
    
    string countOfAtoms(string formula) {
        formula = "(" + formula;
        formula += ")";
        // cout<<formula<<"\n";
        stack<map<string,int>>st;
        map<string,int>mp;
        string str  = "";
        string count = "";
        
        int n = formula.size();
        
        // traverse the string formula
        
        for(int i=0;i<n;i++)
        {
            if(formula[i] == '(')
            {
               if(!str.empty())
               {
                   if(count.empty())
                   {
                      mp[str] += 1; 
                   }
                   
                   else{
                       mp[str] += stoi(count);
                   }
                   str = "";
                   count = "";
                   st.push(mp);
                   mp.clear();
               }
                map<string,int>mpp;
                mpp["("] = 1;
                st.push(mpp);
                
            }
            else if(formula[i] == ')')
            {
                if(!str.empty())
               {
                   if(count.empty())
                   {
                      mp[str] += 1; 
                   }
                   
                   else{
                       mp[str] += stoi(count);
                   }
                   str = "";
                   count = "";
                   st.push(mp);
                   mp.clear();
               }
                
                string cnt = "";
                
                
                while(i+1<n  and formula[i+1] != ')'
                      and formula[i+1] != '(' and !isupperCase(formula[i+1]))
                {
                    cnt += formula[i+1]; i++;
                }
                int numCnt = cnt.empty() ? 1 : stoi(cnt);
                map<string,int>mp_n;
                while(!st.empty() and st.top().find("(") == st.top().end())
                {
                    for(auto x: st.top())
                    {
                        mp_n[x.first] += x.second* numCnt;
                    }
                    st.pop();
                }
                st.pop();
                if(!st.empty() and st.top().find("(") == st.top().end())
                {
                   
                    map<string,int>mp_top = st.top();
                    st.pop();
                    for(auto x: mp_n)
                    {
                        mp_top[x.first] = mp_top[x.first] + x.second;
                    }
                    st.push(mp_top);
                    
                }
                else{
                    
                    st.push(mp_n);
                }
                
            }
            else if(isupperCase(formula[i]))
            {
                 if(!str.empty())
                {
                   if(count.empty())
                   {
                      mp[str] += 1; 
                   }
                   
                   else{
                       mp[str] += stoi(count);
                   }
                   str = "";
                   count = "";
               }
                
                str += formula[i];
             
            }
            else if(islowerCase(formula[i]))
            {
                str += formula[i];
               
            }
            else{
                count += formula[i];
            }
        }
        
        
        string ans;
        
        for(auto x: st.top())
        {
            
            ans += x.first;
            if(x.second > 1)
            {
                ans += to_string(x.second);
            }
        }
        
        return ans;
        
    }
};
