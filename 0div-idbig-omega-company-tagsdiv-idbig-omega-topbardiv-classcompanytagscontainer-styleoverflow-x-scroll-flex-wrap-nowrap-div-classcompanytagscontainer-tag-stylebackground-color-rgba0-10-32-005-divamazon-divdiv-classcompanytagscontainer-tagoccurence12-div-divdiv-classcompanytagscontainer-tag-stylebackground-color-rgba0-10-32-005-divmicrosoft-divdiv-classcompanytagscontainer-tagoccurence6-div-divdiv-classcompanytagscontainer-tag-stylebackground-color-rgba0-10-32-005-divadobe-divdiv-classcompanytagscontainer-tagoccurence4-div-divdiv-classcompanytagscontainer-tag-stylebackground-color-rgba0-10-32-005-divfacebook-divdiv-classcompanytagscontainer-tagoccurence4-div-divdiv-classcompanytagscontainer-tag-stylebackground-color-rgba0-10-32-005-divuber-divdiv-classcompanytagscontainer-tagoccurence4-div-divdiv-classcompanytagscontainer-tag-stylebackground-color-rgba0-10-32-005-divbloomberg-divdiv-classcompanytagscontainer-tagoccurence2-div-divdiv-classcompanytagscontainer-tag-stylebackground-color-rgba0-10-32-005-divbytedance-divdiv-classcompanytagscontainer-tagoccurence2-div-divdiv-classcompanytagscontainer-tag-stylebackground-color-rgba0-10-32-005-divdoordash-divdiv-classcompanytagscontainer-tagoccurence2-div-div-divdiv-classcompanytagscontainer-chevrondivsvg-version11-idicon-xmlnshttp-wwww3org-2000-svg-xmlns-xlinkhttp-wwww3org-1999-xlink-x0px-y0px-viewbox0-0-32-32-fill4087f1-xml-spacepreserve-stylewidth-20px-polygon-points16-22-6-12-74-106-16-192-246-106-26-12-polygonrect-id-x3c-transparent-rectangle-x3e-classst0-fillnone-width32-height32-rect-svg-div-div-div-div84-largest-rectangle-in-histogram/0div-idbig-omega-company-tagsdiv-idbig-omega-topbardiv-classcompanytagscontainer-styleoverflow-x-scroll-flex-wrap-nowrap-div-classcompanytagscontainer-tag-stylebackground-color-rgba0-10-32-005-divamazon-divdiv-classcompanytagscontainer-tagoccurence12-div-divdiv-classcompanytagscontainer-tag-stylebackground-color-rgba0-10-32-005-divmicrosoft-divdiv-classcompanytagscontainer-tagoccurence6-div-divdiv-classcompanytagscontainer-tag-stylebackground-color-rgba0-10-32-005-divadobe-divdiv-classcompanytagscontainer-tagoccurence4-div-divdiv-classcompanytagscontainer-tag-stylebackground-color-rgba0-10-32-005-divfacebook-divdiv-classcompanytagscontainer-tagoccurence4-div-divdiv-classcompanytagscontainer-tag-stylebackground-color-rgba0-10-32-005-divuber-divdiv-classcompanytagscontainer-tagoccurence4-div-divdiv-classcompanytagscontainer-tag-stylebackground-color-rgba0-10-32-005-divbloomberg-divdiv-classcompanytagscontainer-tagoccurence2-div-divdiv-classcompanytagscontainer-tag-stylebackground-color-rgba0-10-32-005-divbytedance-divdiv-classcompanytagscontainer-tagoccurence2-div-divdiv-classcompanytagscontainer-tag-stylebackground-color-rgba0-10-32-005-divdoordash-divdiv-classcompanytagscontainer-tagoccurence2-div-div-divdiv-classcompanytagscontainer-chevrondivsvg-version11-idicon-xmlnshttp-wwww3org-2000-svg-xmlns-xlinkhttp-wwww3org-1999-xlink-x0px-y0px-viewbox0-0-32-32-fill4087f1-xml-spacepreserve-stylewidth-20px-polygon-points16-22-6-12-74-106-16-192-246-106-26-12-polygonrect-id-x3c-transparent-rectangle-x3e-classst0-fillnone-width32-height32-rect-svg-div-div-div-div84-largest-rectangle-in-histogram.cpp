class Solution {
private: 
    vector<int> nextSmaller(vector<int> &h, int n)
    {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; --i)
        {
            int curr = h[i];
            while (s.top() != -1 and h[s.top()] >= curr)
            {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    vector<int> prevSmaller(vector<int> &h, int n)
    {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for (int i = 0; i < n; i++)
        {
            int curr = h[i];
            while (s.top() != -1 and h[s.top()] >= curr)
            {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        int area = INT_MIN;

        vector<int> next(n);
        vector<int> prev(n);

        next = nextSmaller(heights, n);
        prev = prevSmaller(heights, n);
        
        for(auto i:next)cout<<i<<" ";
        cout<<endl;
        for(auto i:prev)cout<<i<<" ";
        cout<<endl;

        for (int i = 0; i < n; i++)
        {
            int l = heights[i];
            if (next[i] == -1)
            {
                next[i] = n;
            }
            int b = next[i] - prev[i] -1;
            int new_area = l * b;
            area = max(area, new_area);
        }
        return area;
    }
};