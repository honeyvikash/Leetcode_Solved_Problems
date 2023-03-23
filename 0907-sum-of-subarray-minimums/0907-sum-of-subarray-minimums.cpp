class Solution {
public:
    #define MOD 1000000007
    int sumSubarrayMins(vector<int>& a) {
        int n=a.size();
        stack<int>st;
        vector<int>left(n,0);
        vector<int>right(n,0);
        
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && a[st.top()]>=a[i])
            {
                st.pop();
            }
            left[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        
        while(!st.empty())st.pop();
        
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && a[st.top()]>a[i])
            {
                st.pop();
            }
            right[i]=st.empty()?n:st.top();
            st.push(i);
        }
        
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long sum = (long long)a[i] * (long long)(i - left[i]) * (long long)(right[i] - i);
            ans += sum;
            ans %= MOD;
        }

        return ans;
    }
};