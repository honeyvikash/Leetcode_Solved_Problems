class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n = nums1.size();
        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                int n2 = 0;
                set<int> d;
                for (int k = 0; k < n; k++)
                {
                    if (k == i || k == j)
                    {
                        continue;
                    }
                    d.insert(nums2[n2++] - nums1[k]);
                }
                if (d.size() == 1)
                {
                    ans = min(ans, *d.begin());
                }
            }
        }

        return ans;
    }
};