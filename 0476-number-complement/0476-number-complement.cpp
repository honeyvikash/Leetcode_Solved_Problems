class Solution {
public:
    int findComplement(int n) {
        int  total_bits = floor(log2(n)) + 1;
        // Considering number to be 32 bit integer;
        bitset<32> b(n);

        // reversing the bits one by one
        for (int i = 0; i < total_bits; i++)
            b.flip(i);

        // converting bitset to number
        return b.to_ulong();
    }
};