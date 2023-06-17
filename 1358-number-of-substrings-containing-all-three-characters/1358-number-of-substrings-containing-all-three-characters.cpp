class Solution {
public:
    int numberOfSubstrings(string s) {
        int i=0,j=0,cnt=0;
        unordered_map<char,int>m;
        m.clear();
        while(j<s.size())
        {
            m[s[j]]++;
            if(m.size()<3)
            {
                j++;
            }
            else
            {
                while(m.size()==3)
                {
                    cnt+=(s.size()-j);
                    m[s[i]]--;
                    if(m[s[i]]==0)
                    {
                        m.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
            
        }
        return cnt;
    }
};