class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int leftMax = left.size()>0?*max_element(left.begin(),left.end()):0;
        int rightMax = right.size()>0?n-*min_element(right.begin(),right.end()):0;
        return max(leftMax,rightMax);
    }
};