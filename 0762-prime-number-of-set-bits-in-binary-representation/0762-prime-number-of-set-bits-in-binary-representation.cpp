class Solution {
public:
    int countPrimeSetBits(int l, int r) {
        // __builtin_popcount(n);
        int cnt=0;
        for(int i=l;i<=r;i++)
        {
            int x = __builtin_popcount(i);
            if(x==2 || x==3 || x==5 || x==7 || x==11 || x==13 || x==17 ||x==19)cnt++;
        }
        return cnt;
    }
};