class Solution {
public:
    int findMin(vector<int>& a) {
        int s=0,e=a.size()-1;
        while(s<e)
        {
            int m = s+(e-s)/2;
            if(a[m]>a[e]) s=m+1;
            else e=m;
        }
        return a[s];
    }
};