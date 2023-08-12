class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n = a.size();
        int length = 1;
        vector<int>ans;
        ans.push_back(a[0]);
        for(int i=1;i<n;i++)
        {
            if(a[i]>ans.back())
            {
                ans.push_back(a[i]);
                length++;
            }
            else
            {
                int idx = lower_bound(ans.begin(),ans.end(),a[i])-ans.begin();
                ans[idx] = a[i];
            }
        }
        return length;
    }
};