class Solution {
public:
    int longestOnes(vector<int>& a, int k) {
        //variable size sliding window
        int maxi = 0;
        int i=0;
        int cnt=0;
        
        for(int j=0;j<a.size();j++)
        {
            cnt+=a[j];
            if (j - i + 1 - cnt <= k)
                maxi = max(maxi, j - i + 1);
            else
                cnt -= a[i++];
        }
        return maxi;
    }
};