class Solution {
public:
    int dfs(int node,int parent,vector<vector<vector<int>>> &adj){
        int cost = 0;
        for(auto val : adj[node]){
            if( parent!=val[0] ){
                cost += val[1];
                cost += dfs(val[0],node,adj);
            }
        }
        return cost;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<vector<int>>> adj(n);
        for(auto val : connections){
            adj[val[0]].push_back({val[1],1});
            adj[val[1]].push_back({val[0],0});
        }
        return dfs(0,-1,adj);
    }
};