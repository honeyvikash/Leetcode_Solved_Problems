class FrontMiddleBackQueue {
public:
    deque<int> a,b;
    void ab()
    {
        if(a.size()<=b.size())
        return;
        b.push_front(a.back());
        a.pop_back();
    }
    void ba()
    {
        if(b.size()<=a.size()+1)
        return;
        a.push_back(b.front());
        b.pop_front();
    }
    FrontMiddleBackQueue() {}
    
    void pushFront(int val) {
        a.push_front(val);
        ab();
    }
    
    void pushMiddle(int val) {
        a.push_back(val);
        ab();
    }
    
    void pushBack(int val) {
        b.push_back(val);
        ba();
    }
    
    int popFront() {
        if(a.size()==0 && b.size()==0)
        return -1;
        int ans;
        if(a.size()==0)
        {
            ans = b.front();
            b.pop_front();
        }
        else
        {
            ans = a.front();
            a.pop_front();
            ba();
        }
        return ans;
    }
    
    int popMiddle() {
        if(a.size()==0 && b.size()==0)
        return -1;
        int ans;
        if(a.size()==b.size())
        {
            ans = a.back();
            a.pop_back();
        }
        else
        {
            ans = b.front();
            b.pop_front();
        }
        return ans;
    }
    
    int popBack() {
        if(a.size()==0 && b.size()==0)
        return -1;
        int ans = b.back();
        b.pop_back();
        ab();
        return ans;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */