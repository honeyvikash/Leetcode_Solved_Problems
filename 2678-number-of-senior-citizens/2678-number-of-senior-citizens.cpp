class Solution {
public:
    int countSeniors(vector<string>& a) {
        int n = a.size();
        int cnt=0;
        int i=0;
       
        for(int i =0;i<n;i++)
        {
            string p = a[i];
            int aa=p[11]-'0';
            int kk=p[12]-'0';
            int age = 10*aa+kk;
            if(age>60)cnt++;
        }
        return cnt;
    }
};
