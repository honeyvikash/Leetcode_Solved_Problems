class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        long long ans = 0;
        vector<int> valid_cnt = vector<int>(26, 0);
        for (auto t: word2) {
            valid_cnt[t - 'a'] += 1;
        }
        vector<int> cnt = vector<int> (26, 0);
        int p = 0;
        int q = 0;
        while (p < word1.size()) {
            // [q, p];
            cnt[word1[p] - 'a'] += 1;
            bool ok = true;
            for (int i = 0; i < 26; ++i) {
                if (cnt[i] < valid_cnt[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                // cout << p << "ok, get addition " << word1.size() - p <<endl; 
                ans += word1.size() - p;
                while (q <= p) {
                    cnt[word1[q] - 'a'] -= 1;
                    if (cnt[word1[q] - 'a'] < valid_cnt[word1[q] - 'a']) {
                        q += 1;
                        break;
                    }
                    ans += word1.size() - p;
                    q += 1;
                }
                // cout << "q is " << q <<endl;
            } 
            p += 1;
        }
        return ans;
    }
};