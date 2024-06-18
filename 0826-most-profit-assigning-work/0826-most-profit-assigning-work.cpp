class Solution {
public:
    int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& w) {
        
        int n = d.size();
        vector<pair<int,int>> pv(n,pair<int,int>());

        for(int i = 0 ; i < n ; ++i)
        {
            pv[i] = {p[i],d[i]};
        }

        sort(pv.begin(),pv.end(),[](pair<int,int>&a,pair<int,int>&b)
        {
            return a.first>b.first || (a.first==b.first && a.second < b.second);
        });
        sort(w.rbegin(),w.rend());

        int si = 0,ms=w.size(),ans=0;
        for(int i = 0 ; i < n ; ++i)
        {
            int l = si , r = ms-1 , idx = -1;

            while(l<=r)
            {
                int m = l+(r-l)/2;

                if(w[m]>=pv[i].second)
                {
                    idx = m;
                    l = m+1;
                }
                else
                {
                    r = m-1;
                }
            }

            if(idx!=-1)
            {
                ans += pv[i].first * (idx-si+1);
                si = idx+1;
            }
            if(si==ms)
                break;
        }
        return ans;
    }
};