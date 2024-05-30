class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int i,n=arr.size(),j,k;
        int count=0;
        unordered_map<int,int> cnt,exc;
        cnt[0] = 1;
        int pf = 0;
        for(i=0;i<n;++i)
        {
            pf^=arr[i];
            count += cnt[pf]++*(i) - exc[pf];
            exc[pf]+=i+1;
        }
        return count;
    }
};