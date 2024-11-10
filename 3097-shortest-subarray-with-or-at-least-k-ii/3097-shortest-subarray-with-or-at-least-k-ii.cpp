class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 1, r = n, mid, answer = -1;
        while(l <= r) {
            mid = (l + r) / 2;
            if (ok(mid, n, nums, k)) {
                answer = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return answer;
    }
private:
    bool ok(int x, int &n, vector<int> &nums, int &k) {
        int i = 0, j = 0;
        vector<int> freq(32, 0);
        while (i < n) {
            while(j < n && j - i < x) {
                update(nums[j], freq, 1);
                j++;
            }
            if (j - i == x && get(freq) >= k) {
                return true;
            }
            update(nums[i], freq, -1);
            i++;
        }
        return false;
    }
    void update(int x, vector<int> &freq, int val) {
        int idx = 0;
        while(x) {
            if (x % 2) {
                freq[idx] += val;
            }
            x /= 2;
            idx++;
        }
    }
    int get(vector<int> &freq) {
        int val = 0;
        for (int i = 0; i < 32; i++) {
            if (freq[i]) {
                val += (1 << i);
            }
        }
        return val;
    }
};