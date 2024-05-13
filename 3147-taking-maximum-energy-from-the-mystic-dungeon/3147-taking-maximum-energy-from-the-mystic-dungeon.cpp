class Solution {
public:
    int maximumEnergy(vector<int>& e, int k) {
        int n=e.size();
        int ans=INT_MIN;
        for(int i=0;i<min(n,k);i++)
        {
            int cnt=e[i];
            // int maxi=e[i];
            int j=i+k;
            while(j<n)
            {
                cnt=max(cnt+e[j],e[j]);
                j+=k;
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};