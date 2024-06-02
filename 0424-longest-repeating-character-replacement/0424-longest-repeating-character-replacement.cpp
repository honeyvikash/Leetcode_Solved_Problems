class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0,r=0,len=0,mf=0;
        unordered_map<char, int> m;
        int n = s.size();
        for(int r=0;r<n;r++)
        {
            m[s[r]]=m[s[r]]+1;
            mf = max(mf, m[s[r]]);
            if ((r - l + 1) - mf > k) 
            {
                m[s[l]]-=1;
                l++;
            }
            else
            {
                len = max(len, r - l + 1);
            }
        }
        return len;
    }
};