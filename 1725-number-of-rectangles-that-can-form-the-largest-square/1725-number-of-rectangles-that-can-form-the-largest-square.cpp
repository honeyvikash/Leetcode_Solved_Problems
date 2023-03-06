class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& r) {
        vector<int>v;
        for(auto x:r)
        {
            v.push_back({min(x[0],x[1])});
        }
        sort(v.begin(),v.end());
        int cnt=1;
        for(int i=v.size()-2;i>=0;i--)
       {
           if(v[v.size()-1]==v[i])cnt++;
       } 
       return cnt;
    }
};