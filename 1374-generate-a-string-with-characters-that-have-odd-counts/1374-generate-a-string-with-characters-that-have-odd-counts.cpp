class Solution {
public:
    string generateTheString(int n) {
        string s = "";
        if(n==1)return "a";
        if(n%2==1)
        {
            for(int i=1;i<=n-2;i++)
            {
                s+='a';
            }
            s+='b';
            s+='c';
        }
        else
        {
            for(int i=1;i<=n-1;i++)
            {
                s+='a';
            }
            s+='b';
        }
        return s;
    }
};