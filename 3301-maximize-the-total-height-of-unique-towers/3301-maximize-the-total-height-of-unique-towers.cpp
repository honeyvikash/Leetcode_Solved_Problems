class Solution {
public:
    long long maximumTotalSum(vector<int>& mh) {
        sort(mh.begin(), mh.end());
        
        unordered_map<int,int> cnt;
        long long ans = 0;
        
        for(auto it : mh) 
        {
            if(cnt[it] == 0) 
            {
                ans += it;
                cnt[it] = 1 + cnt[it-1];
            }
            else
            {
                if(it - cnt[it] <= 0) return -1;
                ans += (it - cnt[it]);
                cnt[it] += 1 + cnt[it - cnt[it] - 1];
            }
        }
     return ans;
    }
};