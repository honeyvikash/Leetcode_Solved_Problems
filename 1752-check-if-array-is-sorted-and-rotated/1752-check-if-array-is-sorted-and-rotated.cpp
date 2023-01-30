class Solution {
public:
    bool check(vector<int>& a) {
        int c = 0,n=a.size();
        for (int i = 0; i < n; i++) if (a[i] > a[(i + 1) % n]) c++;
        return (c <= 1);
    }
};