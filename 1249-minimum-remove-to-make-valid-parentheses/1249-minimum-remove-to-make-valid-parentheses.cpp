class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans = "";
        int vr = 0;
        vector<int> st;

        for(auto&a:s)
        {
            if(a=='(')
            {
                vr++;
                ans+=a;
                st.push_back(ans.size()-1);
            }
            else if(a==')')
            {
                if(vr>0)
                {
                    vr--;
                    ans+=a;
                }
            }
            else
            {
                ans+=a;
            }
        }
        reverse(st.begin(),st.end());
        if(vr>0)
        {
            for(int i = 0 ; i < vr ; ++i)
                ans.erase(st[i],1);
        }
        return ans;
    }
};