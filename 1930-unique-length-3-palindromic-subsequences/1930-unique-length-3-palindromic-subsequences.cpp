class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char,int> left,right;
        unordered_set<string> st;
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            if(left.find(s[i])==left.end())
            left[s[i]] = i;
            right[s[i]] = i;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<26;j++)
            {
                if(left.find(j+'a')!=left.end() && right.find(j+'a')!=right.end())
                {
                    if(left[j+'a']<i && right[j+'a']>i)
                    {
                        string tmp ="";
                        tmp+=(j+'a');
                        tmp+=s[i];
                        tmp+=(j+'a');
                        st.insert(tmp);
                    }
                }
            }
        }
        return st.size();
    }
};