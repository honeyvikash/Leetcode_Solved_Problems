class Solution {
public:
    int longestSubsequence(vector<int>& a, int d) {
        int n = a.size();
        map<int,int> m;
        for(auto &i:a)
            m[i] = 1+m[i-d];
        int ans = 0;
        for(auto &i:m)
            ans = max(ans,i.second);
        return ans;
    }
};