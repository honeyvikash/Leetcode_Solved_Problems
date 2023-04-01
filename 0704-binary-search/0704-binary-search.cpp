class Solution {
public:
    int search(vector<int>& a, int t) {
       if(binary_search(a.begin(), a.end(), t))
        {
            int l = lower_bound(a.begin(), a.end(), t) - a.begin();
            int r = upper_bound(a.begin(), a.end(), t) - a.begin() - 1;
            return (l+r)/2;
        }
        return -1;
    }
};