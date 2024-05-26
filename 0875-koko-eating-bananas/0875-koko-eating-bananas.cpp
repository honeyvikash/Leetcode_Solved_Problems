class Solution {
public:
    #define ll long long
    bool kokoaukad(vector<int>&p,ll m,ll h)
    {
        ll time=0;
        for(auto &x:p)
        {
                ll tmp=x/m;
                time+=tmp;
                if(x%m!=0)time++;
        }
        return time<=h;
    }
    int minEatingSpeed(vector<int>& p, int h) {
        int l=1;
        int r=*max_element(p.begin(),p.end());
        while(l<=r)
        {
            int m=l+(r-l)/2;
            
            if(kokoaukad(p,m,h))r=m-1;
            else l=m+1;
        }
        return l;
    }
};