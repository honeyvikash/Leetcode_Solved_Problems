class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long cnt = 0;
        for(auto&a:s)
            cnt+=(a==c);
        return cnt + (cnt*(cnt-1))/2;
    }
};