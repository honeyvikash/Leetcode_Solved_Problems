class Solution {
public:
    bool check(int n) 
    {
        if (n < 2) return false;
        if (n > 2 && n%2 == 0) return false;
        for (int i = 3; i <= sqrt(n); i += 2) if (n % i == 0) return false;
        return true;
    }
    
    int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    
    int mostFrequentPrime(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        unordered_map<int,int> mp;
        for (int i = 0; i < m; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                for (int k = 0; k < 8; k++) 
                {
                    int d = 0, ii = i, jj = j;
                    while (ii >= 0 && jj >= 0 && ii < m && jj < n) 
                    {
                        d *= 10;
                        d += mat[ii][jj];
                        if (d > 10 && check(d)) mp[d]++;
                        ii += dx[k];
                        jj += dy[k];
                    }
                }
            }
        }
        
        int ans = -1, c = 0;
        for (auto &p : mp) 
        {
            if (p.second > c) 
            {
                ans = p.first;
                c = p.second;
            } 
            else if (p.second == c) 
            {
                ans = max(ans, p.first);
            }
        }
        return ans;
    }
};