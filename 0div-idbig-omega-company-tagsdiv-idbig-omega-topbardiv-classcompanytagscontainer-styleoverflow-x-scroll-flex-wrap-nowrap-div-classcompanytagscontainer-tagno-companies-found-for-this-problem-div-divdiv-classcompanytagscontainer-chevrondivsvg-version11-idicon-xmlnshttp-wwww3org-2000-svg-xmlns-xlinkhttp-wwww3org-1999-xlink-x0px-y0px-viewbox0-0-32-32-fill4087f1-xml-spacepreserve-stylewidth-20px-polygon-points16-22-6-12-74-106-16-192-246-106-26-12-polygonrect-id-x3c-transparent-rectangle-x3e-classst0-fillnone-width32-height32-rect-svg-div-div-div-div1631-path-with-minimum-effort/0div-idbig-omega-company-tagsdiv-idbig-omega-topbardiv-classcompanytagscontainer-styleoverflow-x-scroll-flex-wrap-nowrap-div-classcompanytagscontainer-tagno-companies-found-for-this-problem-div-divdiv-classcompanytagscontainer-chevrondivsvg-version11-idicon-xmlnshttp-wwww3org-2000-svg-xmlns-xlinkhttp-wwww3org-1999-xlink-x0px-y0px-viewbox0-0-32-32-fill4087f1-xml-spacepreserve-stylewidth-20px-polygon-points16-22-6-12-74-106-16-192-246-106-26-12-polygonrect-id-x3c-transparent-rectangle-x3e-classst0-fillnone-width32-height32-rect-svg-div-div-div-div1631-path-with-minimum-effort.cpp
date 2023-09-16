class Solution {
public:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    bool isValid(int x,int y,int n,int m)
    {
        if(x>=0 && y>=0 && x<n && y<m)
        return true;
        return false;
    }
    bool solve(int mid,vector<vector<int>>& heights)
    {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        q.push({0,0});
        vis[0][0] = 1;
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if(x==n-1 && y==m-1)
            return true;
            for(int i=0;i<4;i++)
            {
                int newx = x+dx[i];
                int newy = y+dy[i];
                if(isValid(newx,newy,n,m) && !vis[newx][newy] && abs(heights[newx][newy]-heights[x][y])<=mid)
                {
                    vis[newx][newy] = 1;
                    q.push({newx,newy});   
                }
            }
        }
        return false;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        int l =0,r = 1e6;
        int ans = 0;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(solve(mid,heights))
            {
                ans = mid;
                r = mid-1;
            }
            else
            l = mid+1;
        }
        return ans;
    }
};