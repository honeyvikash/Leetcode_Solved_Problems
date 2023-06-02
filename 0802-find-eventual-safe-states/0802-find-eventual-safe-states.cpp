class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int V = graph.size();
        
        vector<int>adj[V];
        
        vector<int>indegree(V,0);
        
	    for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < graph[i].size(); j++)
            {

                int a = graph[i][j];
                adj[a].push_back(i);
                indegree[i]++;
            }
        }
        
        
        queue<int>q;
        vector<int>safestates;
        for(int i = 0;i<V;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            safestates.push_back(node);
            
            for(auto it : adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                {
                    q.push(it);
                }
            }
        }
        
        sort(safestates.begin(),safestates.end());
        
        return safestates;
    }
};