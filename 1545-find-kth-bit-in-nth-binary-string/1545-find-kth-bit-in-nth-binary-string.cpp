class Solution {
public:
    char findKthBit(int n, int k) {
        if (n == 1) return '0';
        int length = (1 << n) - 1;
        int middle = ceil(length/2.0);

        if (middle == k) return '1';
        else if (k < middle) return findKthBit(n - 1, k);

        char ch = findKthBit(n - 1, length - (k-1));
        return ch == '0' ? '1' : '0';
    }
};