#define vi vector<int>
class Solution {
public:
    // 0 ==> blue
    // 1 ==> red
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector< vector<vector<int>> > edges( 2,vector<vector<int>>(n));

        for(auto &val : redEdges)
        {
            edges[1][val[0]].push_back(val[1]);
        }
        for(auto &val : blueEdges)
        {
            edges[0][val[0]].push_back(val[1]);
        }

        // created two-d vector to stroe distance of node x from node 0

        // [0] => represents distance to reach node x with using last edge as blue
        // [1] => represents distance to reach node x with using last edge as red
        vector< vector<int> > dist(2,vector<int>(n,INT_MAX));

        // dist of node 0 in both cases 0
        dist[0][0] = dist[1][0] = 0;
        // inserted node 0 
        // with it's cost and last visiting edge in set

        queue< pair<int,int> > q;
        q.push({0,0});
        q.push({0,1});

        while( !q.empty() )
        {
            auto [node,isRed] = q.front();
            int cost = dist[isRed][node];
            // cout<<node<<" "<<isRed<<" "<<cost<<"\n";
            q.pop();
            for(auto &val : edges[!isRed][node] )
            {
                if( INT_MAX==dist[!isRed][val] )
                {
                    dist[!isRed][val] = cost+1;
                    q.push({val,!isRed});
                }
            }
        }
        vector<int> ans(n);
        for(int i=0 ; i<n ; i++)
        {
            if( dist[0][i]!=INT_MAX || dist[1][i]!=INT_MAX )
                ans[i] = min(dist[0][i],dist[1][i]);
            else
                ans[i] = -1;
        }
        return ans;
    }
};
// we can apply dijstra as we need to find shd
// but we need to create two vector for storing distance