class Solution {
public:
    int returnToBoundaryCount(vector<int>& a) {
        int x=0,ans=0;
        for(auto &it : a)
        {
            for(int i = 0; i < abs(it); i++)
            {
                if(it>0)x++;
                else x--;
            }
            if(x==0) ans++;
        }
        return ans;
    }
};