class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> pq;
        
        pq.push({0,{0,0}}) ;
        //Create the dist 
        vector<vector<int>> dist(n,vector<int> (m,1e9));
        dist[0][0]=0;
        vector<int> dr={-1,0,1,0};
        vector<int> dc={0,-1,0,1};
        
        while(!pq.empty())
        {
            int diff=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            
            if(row==n-1 && col==m-1) return dist[row][col];
            
            for(int i=0;i<4;i++)
            {
                int r=dr[i]+row;
                int c=dc[i]+col;
                if(r<n && r>=0 && c<m && c>=0 && heights[r][c])
                {
                    int newEff=max(abs(heights[r][c]-heights[row][col]),diff);
                    
                    if(newEff<dist[r][c])
                    {
                        dist[r][c]=newEff;
                        pq.push({newEff,{r,c}});
                    }
                }
            }
            
        }
        return -1;
    }
};