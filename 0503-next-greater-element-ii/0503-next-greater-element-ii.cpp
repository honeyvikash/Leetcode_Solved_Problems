class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n, -1);
        for (int i = n - 1; i >= 0; i--)
            st.push(nums[i]);

        for (int i = n - 1; i >= 0; i--)
        {
            if (!st.empty() and st.top() > nums[i])
                ans[i] = st.top();

            else
            {
                while (!st.empty() and st.top() <= nums[i])
                {
                    st.pop();
                }

                if (st.size() > 0)
                    ans[i] = st.top();
            }

            st.push(nums[i]);
        }
        return ans;
    }
};