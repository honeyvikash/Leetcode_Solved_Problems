class Solution {
public:
    int minChanges(string s) {
        int n  = s.size(),res = 0,cnt= 1;
        for(int i = 1;i<n;i++)
        {
             if(s[i]==s[i-1]) cnt++;
             else 
             {
                 if(cnt%2==0)  cnt = 1;
                 else
                 {
                     cnt = 0;
                     res++;
                 }
             }
        }
        return res;
    }
};
