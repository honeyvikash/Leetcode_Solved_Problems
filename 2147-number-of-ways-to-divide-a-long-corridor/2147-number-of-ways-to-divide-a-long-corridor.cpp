class Solution {
public:
int mod = 1e9+7;
    int numberOfWays(string s) {
        long long ans = 1;
        int count = 0;
        int plants = 0;
        for (auto &x : s) 
        {
            if (x == 'S') 
            {
                if (count == 2) 
                {
                    ans *= (plants + 1);
                    ans %= mod;
                    plants = 0;
                    count = 0;
                }
                count++;
            } 
            else 
            {
                if (count == 2) 
                {
                    plants++;
                }
            }
        }
        if (count <= 1 && plants == 0) ans = 0;
        return ans;
    }
};