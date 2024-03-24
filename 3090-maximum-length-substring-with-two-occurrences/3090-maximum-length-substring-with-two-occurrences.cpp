class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        vector <int> a(26, 0);
        
        int i = 0, j = 0, ans = 0;
        while(j < n)
        {
            int idx = s[j] - 'a';
            a[idx]++;
            while(i <= j && a[idx] > 2)
            {
                int id = s[i] - 'a';
                a[id]--;
                i++;
            }
            ans = max(ans, (j - i + 1));
            j++;
        }
        return ans;
    }
};