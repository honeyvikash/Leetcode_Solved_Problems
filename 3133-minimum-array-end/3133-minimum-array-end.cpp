class Solution {
public:
    long long minEnd(int n, int x) {
        vector<bool> v;
        while (x > 0)
        {
            v.push_back(x & 1);
            x /= 2;
        }
        n--;
        int i = 0;
        while (n > 0)
        {
            if (i >= v.size())
            {
                v.push_back(n & 1);
                n /= 2;
            }
            else
            {
                if (!v[i])
                {
                    v[i] = (n & 1);
                    n /= 2;
                }
            }
            i++;
        }
        long long cur = 0LL;
        for (int i = v.size() - 1; i >= 0; i--)
        {
            if (v[i])
            {
                cur = cur * 2 + 1;
            }
            else
            {
                cur = cur * 2;
            }
        }
        return cur;
    }
};