class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
//         Fully Brute
        int n = points.size(), x1, y1, x2, y2, x3, y3, area, max_area = 0;
        for(int i = 0; i < n; i++) {
            x1 = points[i][0], y1 = points[i][1];
            for(int j = 0; j < n; j++) {
                x2 = points[j][0], y2 = points[j][1];
                for(int k = 0; k < n; k++) {
                    x3 = points[k][0], y3 = points[k][1];
                    area = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
                    max_area = max(abs(area), max_area);
                }
            }
        }
        return 0.5 * double(max_area);
    }
};