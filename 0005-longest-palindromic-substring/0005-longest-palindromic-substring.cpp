class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();        
        for (int i = n; i > 1; i--)
        {
            for (int j = 0; j <= (n - i); j++)
            {
                int l = j, r = j + i - 1;
                while (l < r)
                {
                    if (s[l] != s[r]) break;
                    l++;
                    r--;
                }
                if (l >= r) return s.substr(j, i);
            }
        }
        return s.substr(0, 1);
    }
};