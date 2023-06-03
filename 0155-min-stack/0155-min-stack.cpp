class MinStack {
public:
    stack<int>m;
    stack<int>s;
    
//     MinStack() {
        
//     }
    
    void push(int val) {
        s.push(val);
        if(!m.empty())
        {
            m.push(min(val,m.top()));
        }
        else
        {
            m.push(val);
        }
    }
    
    void pop() {
        s.pop();
        m.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return m.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */