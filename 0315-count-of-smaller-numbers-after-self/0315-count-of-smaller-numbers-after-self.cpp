class Solution {
public:
    vector<int> countSmaller(vector<int>& arr) {
        int n = arr.size();
        vector<int> v, ans;
        ans.push_back(0);
        v.push_back(arr[n - 1]);
        for (int i = n - 2; i >= 0; --i)
        {
            auto ind = lower_bound(v.begin(), v.end(), arr[i]);
            if (ind != v.end())
            {
                int dis = distance(v.begin(), ind);
                v.insert(v.begin() + dis, arr[i]);
                ans.push_back(dis);
            }
            else
            {
                ans.push_back(v.size());
                v.push_back(arr[i]);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};