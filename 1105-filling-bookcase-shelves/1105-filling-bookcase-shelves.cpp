class Solution {
public:
    int W;
    int dp[1001][1001];
    int f(int ind, int remainw, int maxh, vector<vector<int>>& books) {
        int n = books.size();

        if (ind >= n) {
            return maxh;
        }
        if(dp[ind][remainw] != -1){
            return dp[ind][remainw];
        }

        int bookh = books[ind][1];
        int bookw = books[ind][0];

        int keep = INT_MAX;
        int notkeep = INT_MAX;

        if (bookw <= remainw) {
            keep = f(ind + 1, remainw - bookw, max(maxh, bookh), books);
        }
        notkeep = maxh + f(ind + 1, W - bookw, bookh, books);

        return dp[ind][remainw] = min(keep, notkeep);
    }

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        W = shelfWidth;
        memset(dp,-1,sizeof(dp));
        return f(0, shelfWidth, 0, books);
    }
};
