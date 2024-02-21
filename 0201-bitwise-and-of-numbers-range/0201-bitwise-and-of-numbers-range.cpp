class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int right_shift=0;
        while(left!=right)
        {
            left=left>>1;
            right=right>>1;
            right_shift++;
        }
        return left<<right_shift;
    }
};