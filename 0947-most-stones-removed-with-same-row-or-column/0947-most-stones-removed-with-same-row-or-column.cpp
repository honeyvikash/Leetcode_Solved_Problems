class DisjointSet {
    
public: 
    vector<int> rank, parent, size; 
    DisjointSet(int n) 
{
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findUPar(int node) 
   {
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }

    void unionByRank(int u, int v) 
 {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v; 
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u; 
        }
        else {
            parent[ulp_v] = ulp_u; 
            rank[ulp_u]++; 
        }
    }

    void unionBySize(int u, int v)
 {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) 
    {
        int n=stones.size();
        if(n==1)return 0;
        int r=0,c=0;
        for(auto it:stones)
        {
            r=max(r,it[0]);
            c=max(c,it[1]);
        }
        DisjointSet ds(r+c+1);
        for(auto it:stones)
        {
            int row=it[0];
            int col=it[1];
            col+=r+1;
            ds.unionBySize(row,col);
        }
        set<int>st;
        for(int i=0;i<r+c;i++)
        {
            int par=ds.findUPar(i);
            if(ds.size[par]>1)
                st.insert(par);
        }
        int components=st.size();
        // cout<<components<<endl;
        return n-components;
        
    }
};