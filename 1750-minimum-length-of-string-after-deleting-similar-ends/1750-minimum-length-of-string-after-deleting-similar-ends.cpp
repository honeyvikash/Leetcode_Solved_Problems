class Solution {
public:
    int minimumLength(string s) {
        if(s.size()==1)
            return 1;
        int n = s.size();
        if(s[0]!=s[n-1])
            return n;
        int l = 0,r = n-1;
        while(1)
        {
            char c = s[l];
            int len = r-l+1;
            while(l<n && s[l]==c)
            {
                l++;
            }
            while(r>=0 && s[r]==c)
            {
                if(r-1>=0 && r-1==l)
                    return 1;
                r--;
            }
            if(l>=r)
            {
                return 0;
            }
            if(s[l]!=s[r])
                return r-l+1;
        }
        return -1;
    }
};