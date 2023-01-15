class Solution {
public:
    // :(((((((((((((((((((((((((((((((((((
    int fast_find(int x, vector<int>& fu) {
        if (x != fu[x])
            fu[x] = fast_find(fu[x], fu);
        return fu[x];
    }

    void fast_union(int x, int y, vector<int>& fu) {
        fu[fast_find(x, fu)] = fast_find(y, fu);
    }

    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        
        // convert edges representation to a graph representation
        vector<vector<int>> graph;
        for (int i = 0; i < n; i++)
            graph.push_back({});
        for (auto elem : edges) {
            graph[elem[0]].push_back(elem[1]);
            graph[elem[1]].push_back(elem[0]);
        }

        // convert vals to a (value, index) representation
        vector<pair<int, int>> nodes;
        for (int i = 0; i < n; i++)
            nodes.push_back({vals[i], i});

        // sort the nodes vector
        sort(nodes.begin(), nodes.end());

        // initialize F&U structure
        vector<int> fu;
        for (int i = 0; i < n; i++)
            fu.push_back(i);

        int ans = 0;

        // calculate the answer 
        int l = 0;
        int r = 0;
        while (r < n) {
            // find the index of the last element that has the same value as the first (l-th) one 
            while (r < n && nodes[l].first == nodes[r].first)
                r++;

            // go though all of the neighbours of each of these nodes and do F&U.
            for (int i = l; i < r; i++) {
                for (auto elem : graph[nodes[i].second]) {
                    if (vals[elem] <= nodes[i].first) {
                        int a = elem;
                        int b = nodes[i].second;
                        if (a < b)
                            swap(a, b);
                        fast_union(a, b, fu);
                    }
                }
            }

            // calculate how many nodes can be connectec to one another
            unordered_map<int, int> cnt;
            cnt.clear();
            
            for (int i = l; i < r; i++)
                cnt[fast_find(nodes[i].second, fu)]++;
            
            // update the answer
            for (auto elem : cnt)
                ans += (elem.second) * (elem.second - 1) / 2;
            
            // update l for the next iteration
            l = r;
        }

        return ans + n;
    }
};