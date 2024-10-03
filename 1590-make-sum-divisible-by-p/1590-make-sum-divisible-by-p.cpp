class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long totalSum = 0;

        for (int num : nums) {
            totalSum += num;
        }

        int remainder = totalSum % p;
        if (remainder == 0) {
            return 0; 
        }

        unordered_map<int, int> prefixModMap;
        prefixModMap[0] = -1;  
        long prefixSum = 0;
        int minLength = n;

        for (int i = 0; i < n; ++i) {
            prefixSum += nums[i];
            int currentMod = prefixSum % p;

            int targetMod = (currentMod - remainder + p) % p;
            if (prefixModMap.find(targetMod) != prefixModMap.end()) {
                minLength = min(minLength, i - prefixModMap[targetMod]);
            }

            prefixModMap[currentMod] = i;
        }

        return (minLength == n) ? -1 : minLength;
    }
};