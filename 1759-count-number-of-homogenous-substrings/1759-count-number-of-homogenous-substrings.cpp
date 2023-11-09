class Solution {
public:
int mod = 1e9+7;
    
    int countHomogenous(string s) {
        int n = s.size();
        long long ans = 0;
        for(int i=0;i<n;i++)
        {
            long long cnt = 1;
            i++;
            while(i<n && s[i]==s[i-1])
            {
                cnt++;
                i++;
            }
            if(i<n)
            i--;
            ans = (ans+(cnt*(cnt+1))/2)%mod;
        }
        return ans;
    }
};