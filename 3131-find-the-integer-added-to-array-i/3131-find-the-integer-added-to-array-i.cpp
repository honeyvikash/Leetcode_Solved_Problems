class Solution {
public:
    int addedInteger(vector<int>& a1, vector<int>& a2) {
        int n = a1.size();
        long long s1=0LL,s2=0LL;
        for(auto i:a1)
        {
            s1+=i;
        }
        for(auto i:a2)
        {
            s2+=i;
        }
        return (s2-s1)/n;
    }
};