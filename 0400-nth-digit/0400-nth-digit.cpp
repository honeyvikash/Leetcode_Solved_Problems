class Solution {
public:
    int findNthDigit(int n) {
        int l=1,s=1;
        long c=9;
        while(n>l*c)
        {
            n-=(l*c);
            l++;
            c*=10;
            s*=10;
        }
       s+=(n-1)/l;
       string str = to_string(s);
       return (str[(n-1)%l])-'0';
    }
};