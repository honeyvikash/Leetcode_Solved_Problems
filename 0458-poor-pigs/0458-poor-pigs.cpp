class Solution {
public:
    int poorPigs(int b, int md, int mt) {
        return ceil(log2(b)/log2(mt / md + 1));
    }
};