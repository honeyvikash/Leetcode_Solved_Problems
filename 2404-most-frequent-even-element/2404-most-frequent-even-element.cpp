class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> m;
        sort(nums.begin(), nums.end());
        int max = -1;
        int maxi = -1;
        for (auto it : nums)
        {
            m[it]++;
            if (m[it] > max && it % 2 == 0)
            {
                maxi = it;
                max = m[it];
            }
        }
        return maxi;
    }
};