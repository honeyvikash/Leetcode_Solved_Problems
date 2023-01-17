class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int cnt=0;
        int ans=0;
        for(char &x:s)
        {
            if(x=='1')cnt++;
            else
            {
                ans++;
            }
            ans=min(ans,cnt);
        }
        return ans;
    }
};