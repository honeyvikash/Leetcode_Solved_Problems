class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;
        int balance = 0;
        auto m = unordered_map<int, int>{};
        m.emplace(0, -1);

        for (int i = 0; i < n; i++) 
        {
            balance += (nums[i] << 1) - 1;
            auto it = m.find(balance);
            if (it == m.end()) 
            {
                m.emplace_hint(it, balance, i);
            } else 
            {
                ans = max(ans, i - it->second);
            }
        }
        return ans;
    }
};