class Solution {
public:
    vector<int> numOfBurgers(int t, int c) {
        if(t&1)
            return {};
        t/=2;
        t-=c;
        if(t<=c && t>=0)
            return {t,c-t};
        return {};
    }
};