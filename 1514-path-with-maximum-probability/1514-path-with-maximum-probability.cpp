class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& s, int start, int end) {
        vector<vector<pair<int,double>>> adj(n);
        for(int i=0;i<edges.size();i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];
            double dis = s[i];
            adj[a].push_back({b,dis});
            adj[b].push_back({a,dis});
        }
        vector<double> dist(n);
        dist[start] = -1;
        priority_queue<pair<double,int>> pq;
        pq.push({1,start});
        while(!pq.empty())
        {
            int node = pq.top().second;
            double prob = pq.top().first;
            pq.pop();
            for(auto &i:adj[node])
            {
                if(dist[i.first]<prob*i.second)
                {
                    dist[i.first] = prob*i.second;
                    pq.push({dist[i.first],i.first});
                }
            }
        }
        return dist[end];
    }
};