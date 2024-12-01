class Solution {
    unordered_map<int, vector<int>> adj;
    unordered_map<int, int> inDegree, outDegree;

    int getStartNode() {
        int start_node = -1;
        for (auto& [node, degree] : outDegree) {
            if (degree - inDegree[node] == 1) return node; // Eulerian path start node
            if (degree > 0) start_node = node;            // Default for Eulerian circuit
        }
        return start_node;
    }

    void getEulerianPath(int start_node, vector<int>& eulerian_path) {
        stack<int> stk;
        stk.push(start_node);

        while (!stk.empty()) {
            int node = stk.top();
            if (!adj[node].empty()) {
                int next_node = adj[node].back();
                adj[node].pop_back();
                stk.push(next_node);
            } else {
                eulerian_path.push_back(node);
                stk.pop();
            }
        }
    }

public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        // Build adjacency list and degree counts
        for (auto& pair : pairs) {
            int from = pair[0], to = pair[1];
            adj[from].push_back(to);
            outDegree[from]++;
            inDegree[to]++;
        }

        // Find start node
        int start_node = getStartNode();

        // Compute Eulerian path
        vector<int> eulerian_path;
        getEulerianPath(start_node, eulerian_path);

        // Build result from Eulerian path
        vector<vector<int>> res;
        for (int i = eulerian_path.size() - 1; i > 0; --i) {
            res.push_back({eulerian_path[i], eulerian_path[i - 1]});
        }
        return res;
    }
};