class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int len{0}, maxlen{0}, maxi{0};
        for (const int num : nums) {
            if (num < maxi) {
                len = 0;
            }
            else if (num > maxi) {
                maxi = num;
                len = 1;
                maxlen = 1;
            }
            else {
                len++;
                maxlen = std::max(maxlen, len);
            }
        }
        return maxlen;
    }
};