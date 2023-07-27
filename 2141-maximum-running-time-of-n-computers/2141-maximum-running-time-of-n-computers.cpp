class Solution {
public:
    bool solve(long long tim,long long n,vector<int>& b)
    {
        long long tt = n*tim;
        for(auto &i:b)
        {
            tt-=min((long long)tim,(long long)i);
        }
        if(tt<=0)
        return true;
        return false;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        long long ans = 0;
        long long sum = 0;
        for(auto &i:batteries)
        sum+=i;
        long long l = 0,r = sum;
        while(l<=r)
        {
            long long mid = (l+r)/2;
            if(solve(mid,n,batteries))
            {
                ans = mid;
                l = mid+1;
            }
            else
            r = mid-1;
        }
        return ans;
    }
};