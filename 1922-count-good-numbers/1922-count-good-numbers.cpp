class Solution {
public:
    // Binary Exponentiation
    int mod = 1000000007;
    long long Power(long long n,long long k)
    {
        if(k==0)return 1;
        if(k==1)return (n%mod);
        
        long long ans = 1;
        long long kn = Power(n,k/2)%mod;
        
        if(k%2)
        {
            ans = (ans*n)%mod;
        }
        return (ans*((kn*kn)%mod))%mod;
    }
    int countGoodNumbers(long long n) {
        long long res = Power(20,n/2);
        if(n%2)
        {
            res = (res*5)%mod;
        }
        return res;
    }
};