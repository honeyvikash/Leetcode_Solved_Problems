class Solution {
public:
    int numRescueBoats(vector<int>& p, int lim) {
        sort(p.begin(),p.end());
        int n = p.size();
        int ans=0;
        int i=0,j=n-1;
        while(i<j)
        {
            if(p[i]+p[j]<=lim)
            {
                ans++;
                i++;
                j--;
            }
            else
            {
                j--;
                ans++;
            }
        }
        if(i==j)
            ans++;
        return ans;
    }
};