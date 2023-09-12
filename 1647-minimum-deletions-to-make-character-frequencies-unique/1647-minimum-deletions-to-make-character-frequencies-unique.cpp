class Solution {
public:
    int minDeletions(string s) {
        map<char, int> fre;
        map<int, int> m;
        for (auto &i : s)
            fre[i]++;
        int maxi = 0;
        for (auto &i : fre)
            maxi = max(maxi, i.second);
        for (auto &i : fre)
            m[i.second]++;
        for (int i = 0; i <= maxi; i++)
        {
            if (m.find(i) == m.end())
                m[i] = 0;
        }
        int ans = 0;
        auto it = m.end();
        it--;
        while (it != m.begin())
        {
            int siz = it->second;
            if (siz > 1)
            {
                int del = siz - 1;
                ans += del;
                m[(it->first) - 1] += del;
            }
            it--;
            if (it == m.begin() && it->first == 1 && it->second > 1)
                ans += it->second - 1;
        }
        return ans;
    }
};