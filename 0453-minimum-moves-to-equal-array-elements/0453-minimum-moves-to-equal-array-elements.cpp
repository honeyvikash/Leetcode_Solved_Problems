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
    
    int minMoves(vector<int>& a) {
        int n = a.size();
        sort(all(a));
        ll cnt=0;
        for(ll i=0;i<n;i++)
        {
            cnt+=a[i]-a[0];
        }
        return cnt;
    }
};