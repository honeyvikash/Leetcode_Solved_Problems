class Solution {
public:
    int singleNumber(vector<int>& a) {
       //bhaad me jao que
        unordered_map<int,int>m;
        for(auto x:a)m[x]++;
        for(auto x:m)if(x.second==1)return x.first;
        return -1;
    }
};