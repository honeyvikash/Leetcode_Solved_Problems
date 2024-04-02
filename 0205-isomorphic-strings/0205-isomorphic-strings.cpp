class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n1=s.size();
        char mp_s[128]={0};
        char mp_t[128]={0};
        for(int i=0;i<n1;i++)
        {
            if(mp_s[s[i]]!=mp_t[t[i]]) return false;
            
            mp_s[s[i]]=i+1;
            mp_t[t[i]]=i+1;
            
        }
        return true;
    }
};