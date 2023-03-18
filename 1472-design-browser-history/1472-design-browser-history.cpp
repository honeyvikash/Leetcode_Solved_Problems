class BrowserHistory {
    stack<string> backward,st;
public:
    BrowserHistory(string homepage) {
        backward.push(homepage);
    }
    
    void visit(string url) {
        backward.push(url);
        st = stack<string>();
    }
    
    string back(int steps) {
        string currStr;
        while( steps-- && 1!=backward.size() ){
            st.push(backward.top());
            backward.pop();
        }
        return backward.top();
    }
    
    string forward(int steps) {
        while( steps-- && !st.empty() ){
            backward.push(st.top());
            st.pop();
        }
        return backward.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */