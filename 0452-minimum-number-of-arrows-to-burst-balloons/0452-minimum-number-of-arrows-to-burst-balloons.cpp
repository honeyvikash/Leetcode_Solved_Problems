class Solution {
public:
    static bool comparator(vector<int>&v1,vector<int>&v2)
    {
        return v1[1]<v2[1];
    }
    int findMinArrowShots(vector<vector<int>>& p) {
        // similar to merge intervals
        if(p.size()==0)return 0;
        sort(p.begin(),p.end(),comparator);
        int cnt=1;
        int curr=p[0][1];
        for(int i=1;i<p.size();i++)
        {
            if(p[i][0]>curr)
            {
                curr=p[i][1];
                cnt++;
            }
        }
        return cnt;
    }
};