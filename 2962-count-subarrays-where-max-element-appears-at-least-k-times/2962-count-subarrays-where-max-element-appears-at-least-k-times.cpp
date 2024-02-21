class Solution {
public:
    long long countSubarrays(vector<int>& a, int k) {
        int n = a.size();
        unordered_map<int, long long> mp;
        int target = *max_element(a.begin(), a.end());
        int j = 0;
        long long ans = 0;
        for (int i = 0; i < n; i++) 
        {
            mp[a[i]]++;
            while (j <= i and mp[target] >= k) 
            {
                mp[a[j++]]--;
            }
            ans += i + 1;
            ans -= i - j + 1;
        }
        return ans;
    }
};