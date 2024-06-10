class Solution {
public:
    bool canJump(vector<int>& a) {
        // Greddy Approach
        int n= a.size();
        int maxIdx=0;
        for(int i=0;i<=maxIdx;i++)
        {
            maxIdx=max(maxIdx,a[i]+i);
            if(maxIdx>=n-1)return 1;
        }
        return 0;
    }
};