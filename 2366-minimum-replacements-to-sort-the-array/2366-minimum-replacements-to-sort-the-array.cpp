class Solution {
public:
    #define ll long long
    long long minimumReplacement(vector<int>& a) {
        ll n =  a.size();
        ll ans = 0;
        ll maxR = a[n-1];
        for(int i=n-2;i>=0;i--)
        {
            if(a[i]<=maxR)
            maxR = a[i];
            else
            {
                if((a[i]%maxR)==0)
                {
                    int val = a[i]/maxR;
                    ans+=(val)-1;
                }
                else
                {
                    int val = (a[i]/maxR)+1;
                    ans+=(val)-1;
                    maxR = a[i]/val;
                }
            }
        }
        return ans;
    }
};