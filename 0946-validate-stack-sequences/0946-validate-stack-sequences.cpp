class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int n = pushed.size();
        int ptr1 = 0,ptr2 = 0;
        while(ptr1<n)
        {
            while(st.size()>0 && st.top()==popped[ptr2])
            {
                st.pop();
                ptr2++;
            }
            st.push(pushed[ptr1++]);
        }
        while(st.size()>0 & ptr2<n && st.top()==popped[ptr2])
        {
            st.pop();
            ptr2++;
        }
        if(st.size()>0)
        return false;
        return true;
    }
};