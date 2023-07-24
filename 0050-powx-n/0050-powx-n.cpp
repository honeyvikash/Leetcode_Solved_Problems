class Solution {
public:
    double myPow(double x, int n) {
        if(n==1)return (double)x;
        if(n==0)return (double)1.0;
        
        long long int dup = n;
        double ans = 1.0;
        if(dup<0)
        {
            dup=(-1*dup);
        }
        while(dup) 
        {
            if(dup%2==1)
            {
                ans*=x;
                dup--;
            }
            else
            {
                x*=x;
                dup/=2;
            }
        }
        if(n<0)return (double)1.0/(double)ans;
        return ans;
    }
};