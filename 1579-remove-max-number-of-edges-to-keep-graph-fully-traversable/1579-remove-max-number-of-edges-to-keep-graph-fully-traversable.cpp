class Dsu{
private:
    vector<int> parent,rank;
public:
    Dsu(int nodes){
        parent = vector<int>(nodes);
        rank =  vector<int>(nodes,0);
        for(int i=0 ; i<nodes ; i++)    parent[i] = i;
    }
    int findParent(int node){
        if( parent[node]==node )    return node;
        else    return parent[node] = findParent(parent[node]);
    }
    void _union(int u,int v){
        u = findParent(u);
        v = findParent(v);
        if( u!=v ){
            if( rank[u]>rank[v] )
                parent[v] = u;
            else if( rank[v]>rank[u] )
                parent[u] = v;
            else{
                parent[v] = u;
                rank[u] += 1;
            }
        }
    }
};
class Solution {
public:
    int helper(vector<vector<int>> &edges,Dsu dsu,int nodes){
        int arq = 0;
        for(auto val : edges){
            if( dsu.findParent(val[0])!=dsu.findParent(val[1]) ){
                dsu._union(val[1],val[0]);
                arq += 1;
            }
        }
        int p = dsu.findParent(1);
        for(int i=1 ; i<=nodes ; i++){
            if( p!=dsu.findParent(i) )  return -1;
        }
        return arq;
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<vector<int>> aliceEdge,bobEdge;
        int req = 0;
        Dsu dsu(n+1);
        for(auto &val : edges){
            if( 1==val[0] )
                aliceEdge.push_back({val[1],val[2]});
            else if( 2==val[0] )
                bobEdge.push_back({val[1],val[2]});
            else{
                if( dsu.findParent(val[1])!=dsu.findParent(val[2]) )
                    req += 1;
                dsu._union(val[1],val[2]);
            }
        }
        int arq = helper(aliceEdge,dsu,n);
        int brq = helper(bobEdge,dsu,n);
        int len = edges.size();
        if( -1==arq || -1==brq )    return -1;
        else    return (len-(req+arq+brq));
    }
};