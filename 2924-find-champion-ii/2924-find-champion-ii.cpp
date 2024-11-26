class Solution {
public:
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
    
    int findChampion(int n, vector<vector<int>>& e) {
        unordered_map<ll,ll>in;
        for(auto &x:e)
        {
            in[x[1]]++;
        }
        ll res=-1;
        for(int i=0;i<n;i++)
        {
            if(res!=-1 and in[i]==0)
            {
                return -1;
            }
            else if(in[i]==0)
            {
                res=i;
            }
        }
        return (int)res;
    }
};