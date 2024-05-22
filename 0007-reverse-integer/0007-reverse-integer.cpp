class Solution {
public:
    int reverse(int x) {
        long long rev=0;
        while(x!=0)
        {
            rev=rev*10+x%10;
            x/=10;
        }
        if(rev>=(-pow(2,31)) && rev<=(pow(2,31)-1))
        {
            return rev;
        }
        return 0;
    }
};