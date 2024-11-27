class Solution {
public:

int bfs(vector<vector<int>>& adj, int n) {
    queue<int> q;
    q.push(0);
    vector<bool> vis(n);
    vis[0] = true;
    int distance = 0;

    while(!q.empty()) {
        int s = q.size();
        for(int i=0;i<s;i++) {
            int curr = q.front();
            q.pop();
            if(curr == n-1)
            return distance;

            for(int ad: adj[curr]) {
                if(!vis[ad]) {
                    vis[ad] = true;
                    q.push(ad);
                }
            }
        }
        distance ++;

    }
    return distance;
}
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        for(int i =0;i<n-1;i++) {
            adj[i].push_back(i+1);
        }

        vector<int> res;
        for(auto& query: queries) {
            adj[query[0]].push_back(query[1]);
            res.push_back(bfs(adj,n));
        }
        return res;
    }
};