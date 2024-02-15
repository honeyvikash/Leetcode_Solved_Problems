class Solution {
public:
    bool hasTrailingZeros(vector<int>& a) {
        int cnt=0;
        for(auto &i:a)
        {
            if((i&1)==0)cnt++;
        }
        return cnt>=2;
    }
};