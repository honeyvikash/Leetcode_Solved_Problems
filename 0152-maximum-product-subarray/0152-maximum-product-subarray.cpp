class Solution {
public:
    int maxProduct(vector<int>& a) {
        int ml = a[0],mr = a[0] ,pro =1;
        bool z = false;
        for(auto x:a)
        {
            pro*=x;
            if(x==0)
            {
                z = true;
                pro = 1;
                continue;
            }
            ml = max(ml,pro);
        }
        pro = 1;
        for(int i=a.size()-1;i>=0;i--)
        {
            pro *= a[i];
            if(a[i]==0)
            {
                z = true;
                pro =1;
                continue;
            }
            mr = max(mr,pro);
        }
        if(z) return max(max(ml,mr),0);
        return max(ml,mr); 
    }
};