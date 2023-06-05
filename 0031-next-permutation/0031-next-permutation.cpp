class Solution {
public:
    void nextPermutation(vector<int>& a) {
        //this que is all about finding break point and swapping with the just greater number to the right of the break point then reversing the rightest part that's all
        int breakpoint  = -1;
        int n = a.size();
        for(int i=n-2;i>=0;i--)
        {
            if(a[i+1]>a[i])
            {
                breakpoint = i;
                break;
            }
        }
        
        if(breakpoint > -1)
        {
            for(int i = n-1;i>breakpoint;i--)
            {
                if(a[i]>a[breakpoint])
                {
                    swap(a[i],a[breakpoint]);
                    break;
                }
            }
        }
        reverse(a.begin()+breakpoint+1,a.end());
    }
};