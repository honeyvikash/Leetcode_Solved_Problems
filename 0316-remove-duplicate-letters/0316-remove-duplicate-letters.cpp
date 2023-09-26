class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> fre(26);
        vector<int> taken(26);
        for(auto &i:s)
        {
            fre[i-'a']++;
        }
        stack<char> st;
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            if(st.size()==0 && taken[s[i]-'a']==0)
            {
                st.push(s[i]);
                fre[s[i]-'a']--;
                taken[s[i]-'a'] = 1;
            }
            else
            {
                while(st.size()>0 && st.top()>s[i] && fre[st.top()-'a']>0 && taken[s[i]-'a']==0)
                {
                    taken[st.top()-'a'] = 0;
                    st.pop();
                }
                if(taken[s[i]-'a']==0)
                {
                    st.push(s[i]);
                    taken[s[i]-'a'] = 1;
                    fre[s[i]-'a']--;
                }
                else
                fre[s[i]-'a']--;
            }
        }
        string ans = "";
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};