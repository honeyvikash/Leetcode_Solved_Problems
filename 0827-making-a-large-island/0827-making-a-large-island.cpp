class DisjointSet{
    public:
    vector<int>parent,size;
    DisjointSet(int n)
    {
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
            size[i]=1;
        }
    }
    int findUParent(int node)
    {
        if(node == parent[node])
        {
            return node;
        }
        return parent[node] = findUParent(parent[node]);
    }
    void unionBySize(int u,int v)
    {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if(ulp_u == ulp_v)
        {
            return;
        }
        if(size[ulp_u] < size[ulp_v])
        {
            // parent[ulp_u] = ulp_v;
            // size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
    private:
    bool isValid(int nrow,int ncol,int n)
    {
        return nrow >= 0 && nrow < n && ncol >= 0 && ncol < n;  
    }
    public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        for(int row=0;row<n;row++)
        {
            for(int col=0;col<n;col++)
            {
                if(grid[row][col] == 0)
                {
                    continue;
                }
                int dr[] = {-1,0,1,0};
                int dc[] = {0,-1,0,1};
                for(int ind=0;ind<4;ind++)
                {
                    int nrow = row + dr[ind];
                    int ncol = col + dc[ind];

                    if(isValid(nrow,ncol,n) && grid[nrow][ncol])
                    {
                        int nodeNo  = row*n+col;
                        int adjNodeNo = nrow*n+ncol;
                        ds.unionBySize(nodeNo,adjNodeNo);
                    }
                }
            }
        }
        int ans = 0;
        for(int row=0;row<n;row++)
        {
            for(int col=0;col<n;col++)
            {
                if(grid[row][col] == 1)
                {
                    continue;
                }
                int dr[] = {-1,0,1,0};
                int dc[] = {0,-1,0,1};
                
                set<int>components;
                
                for(int ind=0;ind<4;ind++)
                {
                    int nrow = row + dr[ind];
                    int ncol = col + dc[ind];
                    
                    if(isValid(nrow,ncol,n) && grid[nrow][ncol])
                    {
                        components.insert(ds.findUParent(nrow*n+ncol));
                    }
                }
                int totalSize = 0;
                for(auto it : components)
                {
                    totalSize  += ds.size[it];
                } 
                ans = max(ans,totalSize+1);
            }
        }
        for(int cellNo=0;cellNo<n;cellNo++)
        {
            ans = max(ans,ds.size[ds.findUParent(cellNo)]);
        }
        return ans;
    }
};