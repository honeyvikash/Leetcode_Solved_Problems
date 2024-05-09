class Solution {
public:
    //Disjoint Set
    vector<int> parent;
    vector<int> rank;
    int findP(int x)
    {
        if(x==parent[x])
        return x;
        return parent[x] = findP(parent[x]);
    }
    void Union(int x,int y)
    {
        int u = findP(x);
        int v = findP(y);
        if(rank[u]>=rank[v])
        {
            rank[u]++;
            parent[v] = u;
        }
        else
        {
            rank[v]++;
            parent[u] = v;
        }
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        rank.resize(n,0);
        parent.resize(n);
        for(int i=0;i<n;i++)
        parent[i] = i;
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> pq;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                int dis = abs(x1-x2)+abs(y1-y2);
                pq.push({dis,{i,j}});
            }
        }
        int ans =0;
        while(!pq.empty())
        {
            int dis = pq.top().first;
            int u = pq.top().second.first;
            int v = pq.top().second.second;
            pq.pop();
            if(findP(u)!=findP(v))
            {
                Union(u,v);
                ans+=dis;
            }
        }
        return ans;
    }
};