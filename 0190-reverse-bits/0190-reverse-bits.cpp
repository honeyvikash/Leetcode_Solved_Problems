class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
         uint32_t answer = 0;
        for (int i = 0; i < 31; i++)
        {
            if ((n & 1) == 1)
            {
                answer |= 1;
            }
            answer <<= 1;
            n >>= 1;
        }
        if ((n & 1) == 1) 
        {
            answer |= 1;
        }
        return answer;
    }
};