class Solution {
public:
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
#define ll long long
#define all(a) (a).begin(), (a).end()
#define in insert
#define pb push_back
#define B break
#define C continue
#define F first
#define S second
#define numberOfDigit(n) ((ll)log10(n) + 1)
//--------
#define setBit(x) __builtin_popcountll(x)
#define zeroBit(x) __builtin_ctzll(x)
//--------
#define MAX(x) *max_element(all(x))
#define MIN(x) *min_element(all(x))
#define SUM(x) accumulate(all(x), 0LL)
#define COUNT(x, u) count(all(x), u)
//--------
#define mod 1000000007
    
    int buyChoco(vector<int>& p, int m) {
        sort(all(p));
        int a = p[0]+p[1];
        if(a>m)return m;
        if(a==m)return 0;
        return m-a;
    }
};