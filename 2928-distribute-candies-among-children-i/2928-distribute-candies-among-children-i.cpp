class Solution {
public:
#define ll long long
    long long distributeCandies(int n, int limit) {
        ll ans = 0;
        for(int i=0;i<=min(limit,n);i++)
        {
            ll a = i;
            int l = 0,r = min((ll)n-a,(ll)limit);
            int b = -1;
            int mini = min((ll)n-a,(ll)limit);
            while(l<=r)
            {
                int mid = (l+r)/2;
                if(n-(a+mid)<=limit)
                {
                    b = mid;
                    r = mid-1;
                }
                else
                    l = mid+1;
            }
            // cout<<a<<" "<<b<<" "<<(n-(a+b))<<'\n';
            if(b>=0)
            ans+=mini-(b-1);
        }
        return ans;
    }
};