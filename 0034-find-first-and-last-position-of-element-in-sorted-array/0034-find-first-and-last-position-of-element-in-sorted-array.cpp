class Solution {
public:
    vector<int> searchRange(vector<int>& a, int t) {
        bool c=false;
        vector<int>v;
        int n=a.size();
        for(int i=0;i<n;i++)
        {
            if(a[i]==t)
            {
                v.push_back(i);
                c=true;
                break;
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            if(a[i]==t)
            {
                v.push_back(i);
                break;
            }
        }
        if(c)return v;
        return {-1,-1};
    }
};