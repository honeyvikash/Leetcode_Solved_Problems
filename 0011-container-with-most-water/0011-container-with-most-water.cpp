class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int i=0,j=len-1;
        int ans = 0;
        while( i<j )
        {
            if( height[i]<height[j] )
            {
                ans = max(ans,(j-i)*height[i]);
                i += 1;
            }
            else
            {
                ans = max(ans,(j-i)*height[j]);
                j -= 1;
            }
        }
        return ans;
    }
};

