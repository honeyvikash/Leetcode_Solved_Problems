class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)
        return {0};
        if(n==2)
        return {0,1};
        vector<int> adj[n];
        for(auto i:edges)
        {
            int a = i[0];
            int b = i[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        queue<int> q;
        vector<int> sizE(n);
        for(int i=0;i<n;i++)
        {
            if(adj[i].size()==1)
            {
                q.push(i);
            }
            sizE[i] = adj[i].size();
        }
        vector<int> ans;
        while(!q.empty())
        {
            int siz = q.size();
            ans.clear();
            for(int i=0;i<siz;i++)
            {
                int node = q.front();
                q.pop();
                ans.push_back(node);
                sizE[node]--;
                for(auto j:adj[node])
                {
                    sizE[j]--;
                    if(sizE[j]==1)
                    {
                        q.push(j);
                    }
                }
            }
        }
        
        return ans;
    }
};