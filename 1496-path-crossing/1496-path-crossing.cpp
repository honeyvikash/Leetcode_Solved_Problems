class Solution {
public:
    bool isPathCrossing(string path) {
        int n = path.size();
        set<pair<int,int>> s;
        int x = 0,y = 0;
        s.insert({0,0});
        for(auto &i:path)
        {
            if(i=='N')
            {
                y++;
            }
            if(i=='S')
            {
                y--;
            }
            if(i=='E')
            {
                x++;
            }
            if(i=='W')
            {
                x--;
            }
            if(s.count({x,y}))
            return true;
            s.insert({x,y});
        }
        return false;
    }
};