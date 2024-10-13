class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int, int>> merge;
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            for (int num : nums[i]) {
                merge.push_back({num, i});
            }
        }

        sort(merge.begin(), merge.end());
        vector<int> cnt(n, 1);
        int less = n;

        int start = 0, end = INT_MAX;
        int l = 0;
        for (int r = 0; r < merge.size(); r++) {
            less -= --cnt[merge[r].second] == 0;

            while (less == 0) {
                if (merge[r].first - merge[l].first < end - start) {
                    start = merge[l].first;
                    end = merge[r].first;
                }
                less += cnt[merge[l].second]++ == 0;
                l++;
            }
        }

        return {start, end};
    }
};