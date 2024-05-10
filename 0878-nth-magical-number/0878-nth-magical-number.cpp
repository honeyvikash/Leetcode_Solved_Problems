class Solution {
public:
    int mod = 1e9+7;
    long long gcd(long long int a, long long int b)
    {
      if (b == 0)
        return a;
      return gcd(b, a % b);
    }
    
    long long lcm(int a, int b)
    {
        return (a / gcd(a, b)) * b;
    }
    
    int nthMagicalNumber(int n, int a, int b) {
        long long l = min(a,b);
        long long lcc = lcm(a,b);
        long long r = n*lcc*1LL;
        long long ans = 0;
        
        while(l<=r)
        {
            long long mid = l+(r-l)/2;
            long long check = mid/a + mid/b -mid/lcc;
            if(check<n)
            {
                l = mid+1;
            }
            else
            {
                ans = mid%mod;
                r = mid-1;
            }
        }
        return int(ans%mod);
    }
};