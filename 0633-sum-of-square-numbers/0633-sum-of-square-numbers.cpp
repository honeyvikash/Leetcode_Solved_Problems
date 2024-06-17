class Solution {
public:
    bool judgeSquareSum(int c) {
        long long l=0,h=sqrt(c);
        while(l<=h)
        {
            long long temp=l*l+h*h;
            if(temp==c)return 1;
            if(temp>c)h--;
            else l++;
        }
        return 0;
    }
};