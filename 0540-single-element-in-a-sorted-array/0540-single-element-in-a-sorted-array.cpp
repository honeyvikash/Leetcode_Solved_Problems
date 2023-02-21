class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        int s=0;
        int e=a.size()-1;
        while(s<=e)
        {
            int m=s+(e-s)/2;
            if(s==e)return a[s];
            else if(m%2==0)
            {
                if(a[m]==a[m+1])
                {
                    s=m+2;
                }
                else
                {
                    e=m;
                }
            }
            else
            {
                if(a[m]==a[m-1])
                {
                    s=m+1;
                }
                else
                {
                    e=m-1;
                }
            }
        }
        return -1;
    }
};