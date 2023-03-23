class Solution {
public:
    int nextGreaterElement(int n) {
        string s=to_string(n);
        int len=s.size();
        int i=len-1;
        while(i>0)
        {
            if(s[i]>s[i-1]) break;
            i--;
        }
        if(i==0)return -1;
        reverse(s.begin()+i,s.end());
        int j = i-1;
        while(i<len)
        {
            if(s[j] < s[i])
            {
                swap(s[j], s[i]);
                break;
            }
            i++;
        }
        long long ans=stoll(s);
        if(ans>INT_MAX)return -1;
        return (int)ans;
    }
};