class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int n=points.size();
        int low = 0;
        int high = 0;
        int mx = 0;
        while(low!=n && high!=n)
        {
            if(points[low][0]!=points[high][0])
            {
                mx = max(mx, points[high][0]-points[low][0]);
                low=high;
            }
            high++;
        }
        return mx;
    }
};