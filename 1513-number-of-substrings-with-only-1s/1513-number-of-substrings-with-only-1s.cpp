class Solution {
public:
    int numSub(string s) {
        int cnt=0;
        int mod=1000000007;
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='1')cnt++;
            else
            {
                cnt=0;
            }
            ans=(ans+cnt)%mod;
        }
        return ans;
    }
};