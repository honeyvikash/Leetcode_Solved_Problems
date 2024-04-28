class Solution {
public:
    pair<int,int> sm(pair<int,int>&a,pair<int,int>&b)
    {
        return {a.first+b.first,a.second+b.second};
    }
    pair<int,int> dfs(int node,int par,int dst,vector<int> ed[],vector<int>& sub)
    {
        pair<int,int> ans = {0,0};
        for(auto &a:ed[node])
            if(a!=par)
            {
                pair<int,int> x = dfs(a,node,dst+1,ed,sub);
                ans = sm(ans,x);
            }

        sub[node] = 1+ans.second;
        return {dst+ans.first,1+ans.second};
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        
        vector<int> ed[n];

        for(auto&a:edges)
            ed[a[0]].push_back(a[1]),
            ed[a[1]].push_back(a[0]);

        vector<int> sub(n,0);

        pair<int,int> x = dfs(0,-1,0,ed,sub);

        sub[0] = x.first;

    
        vector<bool> bv(n,0);
        bv[0] = 1;
        queue<int>q;
        q.push(0);

        while(!q.empty())
        {
            int f = q.front();
            q.pop();

            for(auto &a:ed[f])
            {
                if(!bv[a])
                {
                    sub[a] = sub[f] - 2*sub[a] + n;
                    q.push(a);
                    bv[a] = 1;
                }
            }
        }
        return sub;
    }
};