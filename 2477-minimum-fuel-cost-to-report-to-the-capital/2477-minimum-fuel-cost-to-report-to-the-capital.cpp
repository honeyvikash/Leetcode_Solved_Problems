class Solution {
    long long ans = 0;
    unordered_map<int,vector<int>> adj;
public:
    int dfs(int node,int seats,int parent){
        int mem = 1;
        for(auto val : adj[node] ){
            if( val!=parent ){
                mem += dfs(val,seats,node);
            }
        }
        if( 0!=node )
            ans += ceil(1.0*mem/seats);
        return mem;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        
        for(auto val : roads){
            adj[val[0]].push_back(val[1]);
            adj[val[1]].push_back(val[0]);
        }
        dfs(0,seats,-1);
        return ans;
    }
};