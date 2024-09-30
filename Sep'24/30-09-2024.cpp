class CustomStack {
public:
    stack<int>st;
    int size = 0;
    CustomStack(int maxSize) {
     size = maxSize;   
    }
    
    void push(int x) {
        if(st.size()<size)
         st.push(x);
    }
    
    int pop() {
        if(st.empty()) return -1;
        int val = st.top();
        st.pop();
        return val;
    }
    
    void increment(int k, int val) {
        stack<int>st1,st2;
        
        
        while(st.size()>k){
            st1.push(st.top());
            st.pop();
        }
        
        while(!st.empty()){
            st2.push(st.top()+val);
            st.pop();
        }
        
        while(!st2.empty()){
            st.push(st2.top());
            st2.pop();
        }
        
        while(!st1.empty()){
            st.push(st1.top());
            st1.pop();
        }
        
        
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
