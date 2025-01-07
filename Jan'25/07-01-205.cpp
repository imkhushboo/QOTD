class Solution {
public:
   bool isSubstr(string a ,string b){
    int m = a.size();
    int n = b.size();
    // cout<<a<<" "<<b<<"\n";

    for(int i=0;i<=n-m;i++){
        string st = b.substr(i,m);
        // cout<<st<<"\n";
        if(st == a){
            return true;
        }
    }

    return false;
   }


    vector<string> stringMatching(vector<string>& words) {
        //sort(words.begin(),words.end());
        vector<string>ans;
        int n = words.size();

        for(int i=0;i<n;i++){
            // cout<<words[i]<<"--\n";
            for(int j = 0;j<n;j++){
                if(j == i) continue;
                if(isSubstr(words[i],words[j])){
                    ans.push_back(words[i]);
                    break;
                }
            }
        }

        return ans;
        
    }
};
