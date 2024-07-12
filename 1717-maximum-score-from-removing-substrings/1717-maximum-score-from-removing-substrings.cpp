class Solution {
public:
    int maximumGain(string s, int x, int y) {
        
        int cnt = 0;
        if(x>y)
        {
            stack<char> st;

            for(auto&a:s)
            {
                if(!st.empty() && st.top()=='a' && a=='b')
                {
                    cnt += x;
                    st.pop();
                }
                else
                {
                    st.push(a);
                }
            }

            s = "";
            while(!st.empty())
            {
                s += st.top();
                st.pop();
            }
            reverse(s.begin(),s.end());

            for(auto&a:s)
            {
                if(!st.empty() && st.top()=='b' && a=='a')
                {
                    cnt += y;
                    st.pop();
                }
                else
                {
                    st.push(a);
                }
            }
            return cnt;
        }
        else
        {
            stack<char> st;

            for(auto&a:s)
            {
                if(!st.empty() && st.top()=='b' && a=='a')
                {
                    cnt += y;
                    st.pop();
                }
                else
                {
                    st.push(a);
                }
            }

            s = "";
            while(!st.empty())
            {
                s += st.top();
                st.pop();
            }
            reverse(s.begin(),s.end());

            for(auto&a:s)
            {
                if(!st.empty() && st.top()=='a' && a=='b')
                {
                    cnt += x;
                    st.pop();
                }
                else
                {
                    st.push(a);
                }
            }
            return cnt;
        }
        return cnt;
    }
};