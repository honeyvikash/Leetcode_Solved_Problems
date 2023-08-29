class Solution {
public:
    int bestClosingTime(string s) {
        int n = s.size();
        vector<int> ye(n),no(n);
        for(int i=0;i<n;i++)
        {
            if(s[i]=='Y')
            {
                ye[i]++;
            }
            else
            {
                no[i]++;
            }
            if(i>0)
            {
                ye[i]+=ye[i-1];
                no[i]+=no[i-1];
            }
        }
        int mini = INT_MAX;
        int idx = n;
        // for(int i=0;i<n;i++)
        // cout<<no[i]<<" ";
        // cout<<'\n';
        // for(int i=0;i<n;i++)
        // cout<<ye[i]<<" ";
        for(int i=0;i<n;i++)
        {
            int cnt = 0;
            if(s[i]=='Y')
                cnt++;
            if(i>0)
                cnt+=no[i-1];
                cnt+=ye[n-1]-ye[i];
            if(cnt<mini)
            {
                mini = cnt;
                idx = i;
            }
        }
        if(mini>no[n-1])
            return n;
        return idx;
    }
};