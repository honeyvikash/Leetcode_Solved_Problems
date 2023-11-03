class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>st;
        int cnt=1,i=0;
        while(i<target.size())
        {
            if(cnt==target[i])
            {
                st.push_back("Push");
                i++;
            }
            else
            {
                st.push_back("Push");
                st.push_back("Pop");
            }
            cnt++;
        }
        return st;
    }
};