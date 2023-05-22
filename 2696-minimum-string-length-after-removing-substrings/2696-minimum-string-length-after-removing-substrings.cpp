class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        st.push(s[0]);
        for(int i=1;i<s.size();i++)
        {
            
            if(!st.empty() && s[i]=='B' && st.top()=='A')
            {
                // cout<<st.top()<<" ";
                st.pop();
            }
                
            else if(!st.empty() && s[i]=='D' && st.top()=='C')
            {
                // cout<<st.top()<<" ";
                st.pop();
            }
            else st.push(s[i]);
        }
        return st.size();
    }
};