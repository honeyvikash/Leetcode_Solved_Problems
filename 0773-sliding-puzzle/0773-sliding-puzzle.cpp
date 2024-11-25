class Solution {
public:

    int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<int>> target = {{1,2,3}, {4,5,0}};
        int dx[4] = {1,0,-1,0};
        int dy[4] = {0,1,0,-1};
        map<vector<vector<int>>, int> dist;
        queue<vector<vector<int>>> Q;
        Q.push(board);
        dist[board] = 0;
        while(!Q.empty()) {
            auto currentConfig = Q.front();
            Q.pop();
            int currentDist = dist[currentConfig];
            if(currentConfig == target) {
                return currentDist;
            }
            // find zero position
            int zx = -1, zy = -1;
            for(int i = 0; i < 2; i++) {
                for(int j = 0; j < 3; j++) {
                    if(currentConfig[i][j] == 0) {
                        zx = i, zy = j;
                        break;
                    }
                }
            }
            for(int i = 0; i < 4; i++) {
                int nx = zx + dx[i];
                int ny = zy + dy[i];
                if(nx < 0 || nx >= 2 || ny < 0 || ny >= 3) {
                    continue;
                }
                swap(currentConfig[zx][zy], currentConfig[nx][ny]);
                if(dist.find(currentConfig) == dist.end()) {
                    dist[currentConfig] = currentDist + 1;
                    Q.push(currentConfig);
                }
                // backtrack...
                swap(currentConfig[zx][zy], currentConfig[nx][ny]);
            }
        }
        return -1;
    }
};