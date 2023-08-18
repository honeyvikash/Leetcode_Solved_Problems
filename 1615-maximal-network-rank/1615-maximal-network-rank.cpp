class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        map<pair<int,int>,int> m;
        vector<vector<int>> adj(n);
        for(auto &i:roads)
        {
            int a = i[0];
            int b = i[1];
            m[{a,b}] = 1;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)
                continue;
                int cnt = adj[i].size()+adj[j].size();
                if(m.find({i,j})!=m.end() || m.find({j,i})!=m.end())
                cnt--;
                ans = max(ans,cnt);
            }
        }
        return ans;
    }
};