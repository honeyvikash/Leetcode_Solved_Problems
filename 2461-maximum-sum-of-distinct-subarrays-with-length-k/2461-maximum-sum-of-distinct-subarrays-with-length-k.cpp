class Solution {
public:
    long long maximumSubarraySum(vector<int>& a, int k) {
        unordered_map<int ,int> m;
        long long ans = 0, i = 0, sum = 0;
        
        for(int j=0; j<a.size(); j++)
        {
            m[a[j]]++;
            sum += a[j];
            if(k == j - i + 1) {
                if(m.size() == k) ans = max(ans, sum);
                sum -= a[i];
                m[a[i]]--;
                if(!m[a[i]]) m.erase(a[i]);
                i++;
            }
        }
        return ans;
    }
};