class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0) return 0;
        float a = log(n) / log(4);
        if(ceil(a)==floor(a)) return 1;
        return 0;
    }
};