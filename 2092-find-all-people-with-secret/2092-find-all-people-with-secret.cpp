class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& m, int f) {
        vector<int>time(n,INT_MAX);
        time[0]=0 ;
        time[f]=0 ;

        vector<int>can(n,0);
        can[0]=1;
        can[f]=1;

        vector<pair<int,int>> adj[n];

        for(auto it : m)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        } 

        vector<int>vis(n,0);
        queue<int>q ;
        q.push(f);
        q.push(0);
        vis[f]=1;
        vis[0]=1;

        while(!q.empty())
        {
            int node = q.front() ;
            q.pop();

            for(auto it : adj[node])
            {
                int adjnode = it.first;
                int dis = it.second ;

                if(time[adjnode]>dis)
                {
                    if(dis>=time[node])
                    {
                        time[adjnode]=dis ;
                        can[adjnode]=1;
                        q.push(adjnode);
                        vis[adjnode]=1;
                    }
                }
            }
        }

        vector<int>ans ;
        for(int i=0 ; i<n ; i++)
        {
            if(can[i])
            {
                ans.push_back(i);
            }
        }

        return ans ;
    }
};