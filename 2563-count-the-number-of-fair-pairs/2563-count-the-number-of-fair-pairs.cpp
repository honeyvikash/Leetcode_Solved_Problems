class Solution {
public:
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
#define ll long long int
#define all(a) (a).begin(), (a).end()
#define in insert
#define pb push_back
#define B break
#define C continue
#define F first
#define S second
#define count_set_bits(n) __builtin_popcount(n)
    
    long long countFairPairs(vector<int>& a, int l, int u) {
          int n=a.size();
          sort(all(a));
          ll cnt = 0;
          for (ll i = 0; i < n; i++)
          {
            int idx1 = lower_bound(a.begin() + i + 1, a.end(), l - a[i]) - a.begin();
            int idx2 = upper_bound(a.begin() + i + 1, a.end(), u - a[i]) - a.begin() - 1;
            if (idx1 <= idx2)
            {
              cnt += idx2 - idx1 + 1;
            }
          }
          return cnt;
    }
};