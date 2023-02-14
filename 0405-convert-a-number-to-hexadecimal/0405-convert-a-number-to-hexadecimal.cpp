class Solution {
public:
    char hex(int num) 
    {
        return num < 10 ? '0' + num : 'a' + num - 10;
    }
    string toHex(int num) {
        unsigned n = num;
        string s;
        while (n) {
            s += hex(n % 16);
            n /= 16;
        }
        reverse(s.begin(), s.end());
        return s.empty() ? "0" : s;
    }
};