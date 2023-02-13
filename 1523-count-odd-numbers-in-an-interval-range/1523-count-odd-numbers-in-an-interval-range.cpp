class Solution {
public:
    int countOdds(int l, int h) {
        return l % 2 != 0 && h % 2 != 0 ? (h-l+2) / 2 : (h-l+1) / 2;
    }
};