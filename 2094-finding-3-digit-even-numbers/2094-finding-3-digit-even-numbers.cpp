class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_set<int>st;
        int n = digits.size();
        for(int i=0;i<n;i++)
        {
            int a = digits[i];
            if(a==0)
                continue;
            for(int j=0;j<n;j++)
            {
                if(j==i)
                    continue;
                int b = a*10+digits[j];
                for(int k=0;k<n;k++)
                {
                    if(k==j || k==i)
                        continue;
                    int c = b*10+digits[k];
                    if(c%2==0)
                        st.insert(c);
                }
            }
        }
        vector<int> vec;
        vec.assign(st.begin(),st.end());
        sort(vec.begin(),vec.end());
        return vec;
    }
};