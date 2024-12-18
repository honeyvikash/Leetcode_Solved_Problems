class Solution {
public:
   bool isPrefix(vector<int>& nums, int start1, int end1, int start2, int end2) {
            int len1 = end1 - start1;
            int len2 = end2 - start2;
            if (len1 > len2) return false; // nums1 can't be a prefix if it's longer
            return equal(nums.begin() + start1, nums.begin() + end1, nums.begin() + start2);
        };
    int beautifulSplits(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0; 

        int count = 0;


        for (int i = 1; i < n - 1; i++) {         
            for (int j = i + 1; j < n; j++) {     
                // nums1 = nums[0..i-1], nums2 = nums[i..j-1], nums3 = nums[j..n-1]
                if (isPrefix(nums, 0, i, i, j) || isPrefix(nums, i, j, j, n)) {
                    count++;
                }
            }
        }

        return count;
    }
};