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
    
    int maxMoves(vector<vector<int>>& g) {
        int m=g.size();
        int n=g[0].size();
        
        vector<vector<int>>t(m,vector<int>(n,0));
        for(int j=n-1;j>=0;j--)
        {
            for(int i=0;i<m;i++)
            {
                if(j==n-1)t[i][j]=0;
                else 
                {
                    int maxi = 0;
                    for(int k=-1;k<=1;k++)
                    {
                        int nr = i+k;
                        if(nr>=0 && nr<m && g[i][j]<g[nr][j+1])
                        {
                            maxi = max(maxi,t[nr][j+1]+1);
                        }
                    }
                    t[i][j] = maxi;
                }
            }
            
        }
        int mcnt=0;
        for(int i=0;i<m;i++)
        {
            mcnt = max(mcnt,t[i][0]);
        }
        return mcnt;
    }
};