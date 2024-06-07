class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        sentence+=' ';
        string ans = "";
        string st = "";
        int found = 0;
        
        for(auto x: sentence)
        {
            if(found == 0 and x != ' ')
            {
                st+=x;
                // cout<<st<<"\n";
                if(find(dictionary.begin(),dictionary.end(),st) != dictionary.end())
                {
                    found = 1;
                }
                
            }
            else if(x == ' ')
            {
                if(ans.size() == 0)
                {
                    ans+=st;

                }
                else{
                    ans += " "+st;
                }
                    
                found = 0;
                st = "";
            }
        }
        
        return ans;
        
    }
};
