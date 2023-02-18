class Solution {
public:
    int minMaxDifference(int n) {
        string s1=to_string(n);
        string s2=to_string(n);
        char found,mi;
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]!='9')
            {
                found=s1[i];
                s1[i]='9';
                break;
            }
        }
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]==found)
            {
                s1[i]='9';
            }
        }
        for(int i=0;i<s2.size();i++)
        {
            if(s2[i]!='0')
            {
                mi=s2[i];
                s2[i]='0';
                break;
            }
        }
        for(int i=0;i<s2.size();i++)
        {
            if(s2[i]==mi)
            {
                s2[i]='0';
            }
        }
        return stoi(s1)-stoi(s2);
    }
};