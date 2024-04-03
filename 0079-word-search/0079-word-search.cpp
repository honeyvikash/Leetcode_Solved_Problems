class Solution {
public:
    char visit[6][6];
    int N,M;
    bool solve(int r, int c, int loc, vector<vector<char>>& board, string &s) {
        if(loc == s.size()) return true;        
        if(r < 0 || r >= N || c < 0 || c >= M || visit[r][c] || board[r][c] != s[loc]) return false;
        visit[r][c] = 1;
        if(solve(r - 1, c, loc + 1, board, s)) return true;
        if(solve(r + 1, c, loc + 1, board, s)) return true;
        if(solve(r, c - 1, loc + 1, board, s)) return true;
        if(solve(r, c + 1, loc + 1, board, s)) return true;
        visit[r][c] = 0;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        N = board.size(),M=board[0].size();
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if(solve(i, j, 0, board, word)) return true;
            }
        }
        return false;

    }
};