class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<int>v1(n);
        vector<int>v2(n);
        for(int i=0;i<n;i++)
        {
            v1[i]=intervals[i][0];
            v2[i]=intervals[i][1];
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        int platform=1,ans=1;
        int i=1;
        int j=0;
        while(i<n && j<n)
        {
            if(v1[i]<=v2[j])
            {
                platform++;
                i++;
            }
            else
            {
                platform--;
                j++;
            }
            ans=max(ans,platform);
        }
        return ans;
    }
};