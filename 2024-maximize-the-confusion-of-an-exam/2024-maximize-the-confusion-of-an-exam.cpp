class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int n = s.size();
        int ans = 0;
        int i=0,j=0;
        set<int> st;
        int tmp = k;
        while(j<n)
        {
            if(s[j]=='F' && k>0)
            {
                k--;
                st.insert(j);
            }
            else if(s[j]=='F' && k==0)
            {
                ans = max(ans,j-i);
                i = *st.begin()+1;
                st.erase(st.begin());
                st.insert(j);
            }
            j++;
        }
        ans = max(ans,j-i);
        i = 0,j = 0,k = tmp;
        while(j<n)
        {
            if(s[j]=='T' && k>0)
            {
                k--;
                st.insert(j);
            }
            else if(s[j]=='T' && k==0)
            {
                ans = max(ans,j-i);
                i = *st.begin()+1;
                st.erase(st.begin());
                st.insert(j);
            }
            j++;
        }
        ans = max(ans,j-i);
        return ans;
    }
};