class Solution {
public:
    vector<int> memLeak(int m1, int m2) {
        int i=1;
        while(m1>0 || m2>0)
        {
            if(m1>m2 && m1-i>=0)
            {
                m1-=i;
            }
            else if(m2>m1 && m2-i>=0)
            {
                m2-=i;
            }
            else if(m1==m2 && m1-i>=0)
            {
                m1-=i;
            }
            else
            break;
            i++;
        }
        return {i,m1,m2};
    }
};