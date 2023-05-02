class Solution {
public:
    bool isPrime(int n)
    {
      if(n <= 1)
      {
         return false; 
      }
      for (int i = 2; i * i <= n; i++)
      {
        if (n % i == 0)return false;
      }
      return true;
    }
    int diagonalPrime(vector<vector<int>>& a) {
       int n = a.size(), ans = 0;
        for(int i=0;i<n;i++) 
        {
            if(isPrime(a[i][i]))
                ans = max(ans, a[i][i]);
            if(isPrime(a[i][n-i-1]))
                ans = max(ans, a[i][n-i-1]);
        }
        return ans;
    }
};