class Solution {
public:
    bool isVow(char c)
    {
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'
        || c=='A' || c=='E' || c=='I' || c=='O' || c=='U') return true;
        
        return false;
    }
    bool halvesAreAlike(string s) {
        int rv = 0,lv = 0;
        int n = s.size();
        for(int i=0;i<n/2;i++)
        {
            if(isVow(s[i]))
            rv++;
        }
        for(int i=n/2;i<n;i++)
        {
            if(isVow(s[i]))
            lv++;
        }
        if(rv==lv)
        return true;
        return false;
    }
};