class Solution {
public:
    vector<int> topoSort(unordered_map<int ,vector<int>> &adj ,
    vector<int>&indegree , int n)
    {
        queue<int>q ;
        for(int i=1 ; i<=n ; i++)
        {
            if(indegree[i]==0)
            {
                q.push(i) ;
            }
        }

        vector<int>ans ;
        while(!q.empty())
        {
            int siz = q.size() ;
            while(siz--)
            {
                int node = q.front() ;
                ans.push_back(node);
                q.pop() ;
                for(auto it : adj[node])
                {
                    indegree[it]-- ;
                    if(indegree[it]==0)
                    {
                        q.push(it) ;
                    }
                }
            }
        }

        return ans ;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        //rowGraph 
        int n = k ;
        unordered_map<int ,vector<int>> adjRow ;
        vector<int>Rowindegree(n+1,0) ;

        for(auto it : rowConditions)
        {
            adjRow[it[0]].push_back(it[1]) ;
            Rowindegree[it[1]]++ ;
        }

        vector<int>rowOrder = topoSort(adjRow,Rowindegree,n);

        map<int,int>rows ;
        for(int i=0 ; i<rowOrder.size() ; i++)
        {
            rows[rowOrder[i]]=i ;
        }


        unordered_map<int ,vector<int>> adjColumn ;
        vector<int>Columnindegree(n+1,0) ;

        for(auto it : colConditions)
        {
            adjColumn[it[0]].push_back(it[1]) ;
            Columnindegree[it[1]]++ ;
        }

        vector<int>colOrder = topoSort(adjColumn,Columnindegree,n);


        vector<vector<int>>ans(k,vector<int>(k,0));

        for(int j=0 ; j<colOrder.size() ; j++)
        {
            int cur = colOrder[j] ;
            int rowOfCur = rows[cur] ;

            ans[rowOfCur][j] = cur ;
        }

        if(rowOrder.size()<k || colOrder.size()<k) return {} ;
        return ans ;
    }
};