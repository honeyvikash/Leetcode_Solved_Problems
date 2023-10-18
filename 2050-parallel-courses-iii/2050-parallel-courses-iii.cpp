class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> indeg(n+1);
        vector<vector<int>> adj(n+1);
        for(auto &i:relations)
        {
            int a = i[0];
            int b = i[1];
            indeg[b]++;
            adj[a].push_back(b);
        }
        vector<int> dist(n+1);
        queue<int> q;
        for(int i=1;i<=n;i++)
        {
            if(indeg[i]==0)
            {
                q.push(i);
                dist[i] = time[i-1];
            }
        }
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto &i:adj[node])
            {
                indeg[i]--;
                dist[i] = max(dist[i],dist[node]+time[i-1]);
                if(indeg[i]==0)
                q.push(i);
            }
        }
        return *max_element(dist.begin(),dist.end());
    }
};