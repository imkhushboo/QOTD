class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char>st;
        
        for(auto x: expression){
            if(x== ')'){
                bool trueflag = false;
                bool falseflag = false;
                while(!st.empty() and st.top() != '('){
                    if(st.top() == 't'){
                        trueflag = true;
                    }
                    else{
                        falseflag = true;
                    }
                    st.pop();
                }
                
                st.pop();
                
                if(st.top() == '!'){
                    st.pop();
                    if(trueflag == true){
                        st.push('f');
                    }
                    else{
                        st.push('t');
                    }
                }
                else if(st.top() == '&'){
                    st.pop();
                    if(trueflag && falseflag){
                        st.push('f');
                    }
                    else if(trueflag){
                        st.push('t');
                    }
                    else{
                        st.push('f');
                    }
                    
                }
                else if(st.top() == '|'){
                    st.pop();
                    if(trueflag){
                        st.push('t');
                    }
                    else{
                        st.push('f');
                    }
                }
            }
            else if(x != ','){
                st.push(x);
            }
        }
        
        
        if(st.top() == 't') return true;
        return false;
        
    }
};
