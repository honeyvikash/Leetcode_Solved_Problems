class Solution {
public:
    bool isThree(int n) {
        set<int> st;
        st.insert(1);
        st.insert(n);
        while(n%2==0)
        {
            st.insert(2);
            n/=2;
        }
        for(int i=3;i<=n;i++)
        {
            if(n%i==0)
            {
                st.insert(i);
                n/=i;
            }
        }
        if(n>=1)
            st.insert(n);
        if(st.size()==3)
            return true;
        return false;
    }
};