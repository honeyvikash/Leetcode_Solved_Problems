class Solution {
public:
    int maximumLength(vector<int>& nums) {
        for(auto &a:nums)
            a%=2;
        int ans = 0;
        int oc = 0 , zc = 0 , x = 0 , b = 0;
        
        for(auto &a:nums)
        {
            if(a==1)
                oc++;
        }
        ans = max(ans,oc);
        
        oc = 0;
        for(auto &a:nums)
        {
            if(a==0)
                oc++;
        }
        ans = max(ans,oc);
        oc = 0;
        
        oc = 0 , zc = 0 , x = 0 , b = 0;
        for(auto &a:nums)
        {
            if(a==1 && b==0)
            {
                x++;
                b = 1;
            }
            
            if(b==1 && a == 0)
            {
                x++;
                b = 0;
            }
        }
        ans = max(ans,x);
        oc = 0 , zc = 0 , x = 0 , b = 0;
        for(auto &a:nums)
        {
            if(a==0 && b==0)
            {
                x++;
                b = 1;
            }
            
            if(b==1 && a == 1)
            {
                x++;
                b = 0;
            }
        }
        ans = max(ans,x);
        return ans;
        
    }
};