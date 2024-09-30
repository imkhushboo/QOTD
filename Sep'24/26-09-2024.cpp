class MyCalendar {
public:
    vector<pair<int,int>>vp;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto x: vp){
            // cout<<x.first<<" "<<x.second<<"\n";
            // cout<<start<<" "<<end<<"\n";
            if(x.first<=start and x.second >=end){
                // cout<<"here1\n";
                return false;
            }
            else if(x.first>=start and x.second<=end){
                // cout<<"here2\n";
                return false;
            }
            else if(x.first<=start and start<x.second and end >x.second){
                // cout<<"here3\n";
                return false;
            }
            else if(start<=x.first and x.first<end and  x.second>end){
                // cout<<"here4\n";
                return false;
            }
        }
        vp.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
