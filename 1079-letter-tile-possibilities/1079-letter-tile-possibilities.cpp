class Solution {
public:
    set<string>ans;
    unordered_map<int,int>m;
    string s;
    void solve(string tiles)
    {
        for(int i=0;i<tiles.size();i++)
        {
            if(m[i]!=1)
            {
                s.push_back(tiles[i]);
                m[i]=1;
                ans.insert(s);
                solve(tiles);
                m[i]=0;
                s.pop_back();
            }
        }
    }
    int numTilePossibilities(string tiles) {
        //Backtracking Standard
        solve(tiles);
        return ans.size();
    }
};