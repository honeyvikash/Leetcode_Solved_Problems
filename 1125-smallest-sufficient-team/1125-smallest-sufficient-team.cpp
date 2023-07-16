class Solution {
public:
    int ans;
    vector<int> fans;
    void solve(int idx,vector<vector<string>>& p,map<string,int>& m,vector<int> &ds,map<string,int>& tmp,vector<string>& r)
    {
        if(tmp.size()==m.size())
        {
            if(ans>ds.size())
            {
                ans = ds.size();
                fans.clear();
                for(int i=0;i<ds.size();i++)
                fans.push_back(ds[i]);
            }
            return;
        }
        if(idx>=r.size())
        return;
        if(tmp.find(r[idx])!=tmp.end())
        solve(idx+1,p,m,ds,tmp,r);
        else
        {
            for(int i=0;i<p.size();i++)
            {
                int flg = 0;
                for(auto &j:p[i])
                {
                    if(j==r[idx])
                    {
                        flg = 1;
                        break;
                    }
                }
                if(flg)
                {
                    for(auto &j:p[i])
                    tmp[j]++;
                    ds.push_back(i);
                    solve(idx+1,p,m,ds,tmp,r);
                    ds.pop_back();
                    for(auto &j:p[i])
                    {
                        tmp[j]--;
                        if(tmp[j]==0)
                        tmp.erase(j);
                    }
                }
            }
        }
    }
    vector<int> smallestSufficientTeam(vector<string>& r, vector<vector<string>>& p) {
        ans = INT_MAX;
        map<string,int> m;
        for(auto &i:r)
        m[i]++;
        
        int n = p.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j && includes(p[i].begin(),p[i].end(),p[j].begin(),p[j].end()))
                p[j].clear();
            }
        }
        vector<int> ds;
        map<string,int> tmp;
        solve(0,p,m,ds,tmp,r);
        return fans;
    }
};