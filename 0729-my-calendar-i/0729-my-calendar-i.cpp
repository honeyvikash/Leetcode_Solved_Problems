class MyCalendar {
public:
    map<int,int> m;
    MyCalendar() {
        m.clear();
    }
    
    bool book(int start, int end) {
        auto it = m.upper_bound(start);
        if(it==m.end() || end<=m[(it->first)])
        {
            m[end]=start;
            return true;
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */