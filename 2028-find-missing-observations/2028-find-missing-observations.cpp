class Solution {
public:
    vector<int> missingRolls(vector<int>& a, int mean, int n) {
        
        long long curr = accumulate(a.begin(),a.end(),0);
        
        long long req = mean*(n+a.size()) - curr;
        
        if(req<n or req>(6*n)) return {};
        
        vector<int>ans(n,1);
        
        req-=n;
        
        int ind = 0;
        
        while(req>0)
        {
            while(req>0 and ans[ind]<6)
            {
                ans[ind]++;
                req--;
            }
            if(req>0){
                ind++;
            }
        }
        return ans;
    }
};