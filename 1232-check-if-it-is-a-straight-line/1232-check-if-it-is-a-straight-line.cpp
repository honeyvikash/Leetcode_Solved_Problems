class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        if(n<3)
            return true;
        int y2=coordinates[1][1];
        int y1=coordinates[0][1];

        int x2=coordinates[1][0];
        int x1=coordinates[0][0];
        int flag = 0;
        float m;
        if(x2 == x1)
        {
            flag = 1;
        }
        else
        {
            m= (float)(y2-y1)/(x2-x1);
        }
        for(int i = 2;i<n;i++){
            int y2=coordinates[i][1];
            int y1=coordinates[0][1];

            int x2=coordinates[i][0];
            int x1=coordinates[0][0];
            if(flag == 1)
            {
                if(x2!=x1)
                    return false;
                else
                    continue;
            }
            float t = (float)(y2-y1)/(x2-x1);
            if(abs(t-m)>0.000001)
                return false;
        }
        return true;
    }
};