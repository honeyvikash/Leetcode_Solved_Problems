vector<int> z_function(string s)
{
    int n = (int)s.length();
    vector<int> z(n);
    // consider a window [l,r]
    // which matches with prefix of s
    int l = 0, r = 0;
    z[0] = n;
    for (int i = 1; i < n; ++i)
    {
        // when i<=r, we make use of already computed z
        // value for some smaller index
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);

        // if i>r nothing matches so we will calculate
        // z[i] using naive way.
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        // update window size
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}
class Solution
{
public:
    int minimumTimeToInitialState(string s, int k)
    {
        int n = s.length();
        vector<int> z = z_function(s);
        int ct = 1;
        for (int i = k; i < n; i += k)
        {
            if (z[i] == (n - i))
                return ct;
            ct++;
        }
        return ct;
    }
};