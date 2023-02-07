class Solution {
public:
    int getMaxLen(vector<int>& arr) {
        int n = arr.size();
        int pos = 0, neg = 0;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
            {
                pos = 0;
                neg = 0;
            }
            else if (arr[i] > 0)
            {
                pos++;
                if (neg > 0)
                    neg++;
                ans = max(ans, pos);
            }
            else
            {
                swap(pos, neg);
                neg++;
                if (pos > 0)
                    pos++;
                ans = max(ans, pos);
            }
        }
        return ans;
    }
};