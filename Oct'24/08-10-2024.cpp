class Solution {
public:
    int minSwaps(string s) {
        stack<char>st;
        
        for(auto x:s){
            if(x == '['){
                st.push('[');
            }
            else if(!st.empty() and st.top() == '[') st.pop();
        }
        
        // while(!st.empty()){
        //     cout<<st.top();
        //     st.pop();
        // }
        return st.size()%2 == 0?st.size()/2:st.size()/2+1;
    }
};

