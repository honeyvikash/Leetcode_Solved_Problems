class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& a1, vector<int>& a2) {
//         unique hone ka fayda uthate hue yaha
        unordered_map<int,int>m;
        int n=a2.size();
        vector<int>v;
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && st.top()<a2[i])
            {
                st.pop();
            }
            int ans=st.empty()?-1:st.top();
            m[a2[i]]=ans;
            st.push(a2[i]);
        }
        for(auto x:a1)
        {
            v.push_back(m[x]);
        }
        return v;
        
    }
};