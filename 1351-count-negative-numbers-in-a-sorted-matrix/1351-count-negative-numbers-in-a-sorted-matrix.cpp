class Solution {
public:
int cntNeg(vector<int>v)
{
    int cnt=0;
    int n=v.size();
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++)
    {
        if(v[i]<0)cnt++;
        else break;
    }
    return cnt;
}
    int countNegatives(vector<vector<int>>& grid) {
        int ans=0;
        for(auto &x:grid)
        {
            ans+=cntNeg(x);
        }
        return ans;
    }
};