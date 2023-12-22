class Solution {
public:
#define all(a) (a).begin(), (a).end()
    
    int maxScore(string s) {
        int o = count(all(s), '1');
        int ans = 0;
        int z = 0;
        for (int i = 0; i < s.size() - 1; i++)
        {
            if (s[i] == '1') o--;
            else z++;
            ans = max(ans, z + o);
        }
        return ans;
    }
};