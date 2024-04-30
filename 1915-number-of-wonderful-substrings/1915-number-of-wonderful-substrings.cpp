class Solution {
public:
    long long wonderfulSubstrings(string word) {
        
        unordered_map<int,long long> bmp,mp;

        int i = 0 , j = 0 , n = word.length();
        bmp[0]++;
        long long ans = 0;

        for(int i = 0 ; i < n ; ++i)
        {
            mp[word[i]-'a']++;
            int bm = 0;
            for(auto &[a,b]:mp)
                if(b&1)
                    bm|=(1<<a);

            long long res = 0;

            for(int j = 0 ; j < 10 ; ++j)
            {
                int nbm = ((1<<j)^bm);
                res += bmp[nbm];
            }
            res += bmp[bm];
            bmp[bm]++;
            ans += res;
        }
        return ans;
    }
};