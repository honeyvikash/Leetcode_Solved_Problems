class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<set<int>>ans(n);
        vector<int>indegree(n,0) ;

        vector<int>adj[n] ;
        for(auto it : edges)
        {
            indegree[it[1]]++ ;
            adj[it[0]].push_back(it[1]) ; 
        }

        queue<int>q ;
        

        for(int i=0 ; i<n ; i++)
        {
            if(indegree[i]==0)
            {
                q.push(i) ;
            }
        }
        

        while(!q.empty())
        {
            int sz = q.size() ;

            while(sz--)
            {
                int node = q.front() ;
                q.pop() ;

                 for(auto child : adj[node])
                 {
                       ans[child].insert(node) ;
                        for(auto parents : ans[node]) ans[child].insert(parents) ;

                        indegree[child]-- ;
                        if(indegree[child]==0) q.push(child) ;
                 }
            }
        }

        vector<vector<int>> res(n) ;
        for(int i=0 ; i<n ; i++)
        {
            for(auto it : ans[i])
            {
                res[i].push_back(it) ;
            }
        }

        return res ;
    }
};