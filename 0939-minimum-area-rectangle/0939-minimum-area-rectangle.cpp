class Solution {
public:
    int minAreaRect(vector<vector<int>>& p) {
        map<pair<int,int>,int> m;
        for(auto &x:p)
        {
            m[{x[0],x[1]}]++;
        }

        // for(auto &x:m)
        // {
        //     cout<<x.first.first<<","<<x.first.second<<" "<<x.second<<endl;
        // }

        int ans = INT_MAX;
        for(int i =0 ;i<p.size();i++)
        {
            for(int j=i+1;j<p.size();j++)
            {
                int x1 = p[i][0];
                int y1 = p[i][1];
                int x2 = p[j][0];
                int y2 = p[j][1];

                //hum yaha daigonal ke do khoj rhe hai
                if(x1==x2 || y1==y2)continue;  //mtlb ye diagonals nhi hai

                if(m.find({x1,y2})!=m.end() && m.find({x2,y1})!=m.end()) // mtlb hume points mil gye hai jo chahie
                {
                    int len = abs(x2-x1);
                    int bre = abs(y2-y1);
                    ans = min(ans,len*bre);
                }
            }
        }
        if(ans==INT_MAX)
        return 0;
        return ans;
    }
};