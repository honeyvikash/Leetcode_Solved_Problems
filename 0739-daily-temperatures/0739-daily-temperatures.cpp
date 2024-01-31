class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int  n = t.size();
        vector<int> ans(n,0);
        stack<int> st;
        int j = n-1;
        while(j>=0)
        {
            if(st.empty())
            {
                ans[j]=0;
                st.push(j);
            }
            else
            {
                if(t[st.top()]>t[j])
                {
                      ans[j] = st.top() - j;
                      st.push(j);
                }
                else
                {
                    while(!st.empty() && t[st.top()]<=t[j])
                    {
                        st.pop();
                    }
                     if(st.empty())
                     {
                       ans[j]=0;
                       st.push(j);
                     }
                     else
                     {
                         ans[j] = st.top() - j;
                         st.push(j); 
                     }  
                }
            }
            j--;
        }
        return ans;
    }
};