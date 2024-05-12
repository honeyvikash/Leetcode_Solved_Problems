
class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) 
    {
        vector<pair<int,char>>vec;
        map<int,vector<char>>amap;
        for(int i=0;i<s.size();i++)
        {
            points[i][0]=abs(points[i][0]);          
            points[i][1]=abs(points[i][1]);
            amap[max(points[i][0],points[i][1])].emplace_back(s[i]);
        }
        map<char,bool>bmap;
        int cnt=0;
        for(auto &[a,vec]:amap)
        {
            for(auto &ch:vec)
            {
                if(bmap[ch])
                {
                    return cnt;
                }
                bmap[ch]=true;
            }
            cnt+=vec.size();
        }
        return cnt;
    }
};