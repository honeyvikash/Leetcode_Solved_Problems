class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        int start = 0;
        while (start < n) 
        { 
            if (start + k <= n) 
            {
                reverse(s.begin() + start, s.begin() + start + k);
            } else 
            {
                reverse(s.begin() + start, s.end());
            }
            start += 2 * k;
        }
        return s;
    }
};