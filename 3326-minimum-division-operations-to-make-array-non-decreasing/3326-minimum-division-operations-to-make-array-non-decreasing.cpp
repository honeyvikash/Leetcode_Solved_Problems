class Solution {
public:
    int minOperations(vector<int>& nums) {
        const unsigned n = nums.size();
        int next = INT_MAX;
        vector<int> cache;
        int ret = 0;
        for (unsigned i = n; i--; ) {
            auto cur = nums[i];
            while (cur > next) {
                if (cur >= cache.size())
                    cache.resize(cur + 1);
                if (!cache[cur]) {
                    //cout << cur << '>';
                    for (unsigned step = (cur & 1 ? 2 : 1), v = 1 + step; v*v <= cur; v += step) {
                        //cout << '?' << v << ' ';
                        if (cur % v == 0) {
                            cache[cur] = v;
                            break;
                        }
                    }
                    //cout << cache[cur] << endl;
                    if (!cache[cur])
                        return -1;
                }
                cur = cache[cur];
                ++ret;
            }
            next = cur;
        }
        return ret;
    }
};