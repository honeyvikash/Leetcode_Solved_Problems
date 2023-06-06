class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int t) {
        for(auto &x:m)
        {
            int s=0,e=x.size()-1;
            while(s<=e)
            {
                int mid=s+(e-s)/2;
                if(x[mid]==t)return true;
                else if(x[mid]<t)s=mid+1;
                else e=mid-1;
            }
        }
        return false;
    }
};