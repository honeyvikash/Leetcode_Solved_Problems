class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
        stack<pair<char,int>> st;
        for(int i=0;i<n;i++)
        {
            if(st.size()>0)
            {
                if(st.top().first==s[i])
                {
                    int fre = st.top().second;
                    char c = st.top().first;
                    fre++;
                    st.pop();
                    st.push({c,fre});
                }
                else
                st.push({s[i],1});
            }
            else
            st.push({s[i],1});
            if(st.size()>0 && st.top().second==k)
            st.pop();
        }
        string ans = "";
        while(!st.empty())
        {
            int fre = st.top().second;
            char c = st.top().first;
            while(fre)
            {
                ans+=c;
                fre--;
            }
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};