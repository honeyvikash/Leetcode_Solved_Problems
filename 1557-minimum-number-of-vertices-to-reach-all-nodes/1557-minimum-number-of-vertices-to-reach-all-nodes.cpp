class Solution {
    void dfs(int node,vector<bool> &visited,vector<bool> &isStarting,vector<vector<int>> &edges)
    {
        visited[node] =  true;
        for(auto child : edges[node])
        {
            if( isStarting[child] )
            {
                isStarting[child] = false;
            }
            else if( false==visited[child] )
            {
                dfs(child,visited,isStarting,edges);
            }
        }
    }
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n,false),isStarting(n,false);
        vector<vector<int>> adj(n);
        for(auto &val : edges)  adj[val[0]].push_back(val[1]);
        vector<int> ans;
        for(int i=0 ; i<n ; i++)
        {
            if( false==visited[i] )
            {
                dfs(i,visited,isStarting,adj);
                isStarting[i] = true;
            }
        }
        for( int i=0 ; i<n ; i++ )
        {
            if( isStarting[i] ) ans.push_back(i);
        }
        return ans;
    }
};