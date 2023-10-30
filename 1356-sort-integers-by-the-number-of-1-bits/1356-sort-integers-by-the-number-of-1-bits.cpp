class Solution {
public:
    int countSetBits(int N)
    {
        int count = 0;
        for (int i = 0; i < sizeof(int) * 8; i++) {
            if (N & (1 << i))count++;
        }
        return count;
    }
    vector<int> sortByBits(vector<int>& a) {
        vector<pair<int,int>>m;
        for(int i=0;i<a.size();i++)
        {
            int x=countSetBits(a[i]);
            m.push_back({x,a[i]});
        }
        vector<int>ans;
        sort(m.begin(),m.end());
        for(auto &p:m)
        {
            ans.push_back(p.second);
        }
        return ans;
    }
};