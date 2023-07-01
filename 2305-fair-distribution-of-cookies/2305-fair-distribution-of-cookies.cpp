class Solution {
public:
    int ans;
    void solve(int idx,vector<int>& c,vector<int> ds,int k)
    {
        if(idx==c.size())
        {
            int maxi = INT_MIN;
            for(auto &i:ds)
            {
                maxi = max(maxi,i);
            }
            ans = min(ans,maxi);
            return;
        }
        for(int i=0;i<k;i++)
        {
            ds[i]+=c[idx];
            solve(idx+1,c,ds,k);
            ds[i]-=c[idx];
            if(ds[i]==0)
            break;
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> ds(k);
        ans = INT_MAX;
        solve(0,cookies,ds,k);
        return ans;
    }
};