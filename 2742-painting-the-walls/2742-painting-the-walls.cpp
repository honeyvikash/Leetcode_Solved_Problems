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
    
    int dp[501][501];
    int solve(int idx,vector<int>& cost,vector<int>& time,int rem)
    {
        if(rem<=0)
            return 0;
        if(idx>=cost.size())
            return 1e9;
        if(dp[idx][rem]!=-1)
            return dp[idx][rem];
        
        int tak = cost[idx]+solve(idx+1,cost,time,rem-time[idx]-1);
        int notTak = solve(idx+1,cost,time,rem);
        
        return dp[idx][rem] = min(tak,notTak);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        memset(dp,-1,sizeof(dp));
        int n = cost.size();
        return solve(0,cost,time,n);
    }
};