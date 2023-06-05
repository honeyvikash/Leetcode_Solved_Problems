class Solution {
public:
    void sortColors(vector<int>& a) {
        int z=0,o=0,t=0;
        for(int i=0;i<a.size();i++)
        {
            if(a[i]==0)z++;
            else if(a[i]==1)o++;
            else t++;
        }
        int i = 0;
        while(z--)
        {
            a[i++]=0;
        }
        while(o--)
        {
            a[i++]=1;
        }
        while(t--)
        {
            a[i++]=2;
        }
    }
};