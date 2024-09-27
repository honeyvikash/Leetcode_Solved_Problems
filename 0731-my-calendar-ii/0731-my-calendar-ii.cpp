class MyCalendarTwo {
public:
    map<int,int>m;
    MyCalendarTwo() {
        m.clear();
    }
    
    bool book(int start, int end) {
        m[start]++;
        m[end]--;
        int cnt=0;
        for(auto i:m)
        {
            cnt+=i.second;
            if(cnt>2)
            break;
        }
        if(cnt>2)
        {
            m[start]--;
            m[end]++;
            return false;
        }
        return true;
    }
};