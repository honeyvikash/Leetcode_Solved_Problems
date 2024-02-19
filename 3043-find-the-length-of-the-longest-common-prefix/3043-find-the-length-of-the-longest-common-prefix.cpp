class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        set<string> st;
        for (auto &x : arr1) 
        {
            string s = to_string(x);
            string prefix = "";
            for (auto &ch : s) 
            {
                prefix += ch;
                st.insert(prefix);
            }
        }
        
        int maxi = 0;
        for (auto &y : arr2) 
        {
            string s = to_string(y);
            string prefix = "";
            for (auto &ch : s) 
            {
                prefix += ch;
                if (st.find(prefix) != st.end()) 
                {
                    maxi = max(maxi, (int)prefix.size());
                }
            }
        }
        return maxi;
    }
};