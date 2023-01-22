class Solution {
public:
    int getCommon(vector<int>& a1, vector<int>& a2) {
        map<int,int>m1;
        for(auto &x:a1) m1[x]++;
        for(auto &x:a2)
        {
            if(m1[x])return x;
        }
        return -1;
    }
};