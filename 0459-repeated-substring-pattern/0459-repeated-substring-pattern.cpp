class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        string tmp = "";
        for(int i=0;i<n-1;i++)
        {
            tmp+=s[i];
            int flg = 0;
            for(int j=0;j<n;)
            {
                if(j+tmp.size()-1>=n)
                {
                    flg = 1;
                    break;
                }
                string tmp1 = s.substr(j,tmp.size());
                if(tmp1!=tmp)
                {
                    flg = 1;
                    break;
                }
                else
                j+=tmp.size();
            }
            if(!flg)
            return true;
        }
        return false;
    }
};