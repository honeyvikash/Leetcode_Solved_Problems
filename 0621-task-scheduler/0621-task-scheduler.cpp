class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int ans = 0;
        unordered_map<char,int> m;
        int cnt = 0;
        for(auto &x:tasks)
        {
            m[x]++;
            cnt = max(cnt,m[x]);
        }
        ans = (cnt-1)*(n+1);
        for(auto &x:m)
        {
            if(x.second==cnt)
            ans++;
        }
        return max((int)tasks.size(),ans);
    }
};