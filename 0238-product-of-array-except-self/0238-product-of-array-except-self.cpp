class Solution {
public:
    vector<int> productExceptSelf(vector<int>& a) {
        long long pro=1;
        bool check=false;
        int cnt=0;
        for(auto &x:a)
        {
            if(x==0)
            {
                cnt++;check=true;
            }
            else pro*=x;
        }
        if(cnt>1)
        {
            for(int i=0;i<a.size();i++)a[i]=0;
        }
        else
        {
            for(int i=0;i<a.size();i++)
            {
                if(check && a[i]!=0)a[i] = 0;
                else if(a[i]==0)a[i]=pro;
                else a[i] = (pro/a[i]);
            }
        }
        
        return a;
    }
};