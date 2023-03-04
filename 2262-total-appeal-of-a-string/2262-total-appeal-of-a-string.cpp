class Solution {
public:
#define ll long long 
    ll solve(string s, char c)
    {
        ll n=s.size();
        ll cnt=0;
        ll temp_ans=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]==c)
            {
               temp_ans+=(cnt*(cnt+1)/2);
               cnt=0; 
            }
            else cnt++;
        }
        temp_ans+=(cnt*(cnt+1)/2);
        return (n*(n+1)/2)-temp_ans;

    }
    long long appealSum(string s) {
        ll ans=0;
        for(char c='a';c<='z';c++)
        {
            ans+=solve(s,c);
        }
        return ans;
    }
};