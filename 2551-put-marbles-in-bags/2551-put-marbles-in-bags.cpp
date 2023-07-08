class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if(k==1 || n==k)
        return 0;
        vector<long long> vec;
        for(int i=1;i<n;i++)
        {
            vec.push_back(weights[i]+weights[i-1]);
        }
        sort(vec.begin(),vec.end());
        long long mins = 0,maxs = 0;
        for(int i=0;i<k-1;i++)
        {
            mins+=vec[i];
            maxs+=vec[vec.size()-i-1];
        }
        return maxs-mins;
    }
};