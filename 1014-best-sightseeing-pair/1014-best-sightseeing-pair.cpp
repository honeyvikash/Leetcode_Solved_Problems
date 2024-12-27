class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        vector<int> v(n,0);
        int maxi=values[0];

        for(int i=1;i<n;i++)
        {
            v[i]= --maxi;
            if(values[i]>=maxi)
                maxi=values[i];          
        }

        int ans=INT_MIN;
        for(int i =1;i<n;i++)
        {
            ans = max(ans , v[i] + values[i]);
        }

        return ans;
    }
};