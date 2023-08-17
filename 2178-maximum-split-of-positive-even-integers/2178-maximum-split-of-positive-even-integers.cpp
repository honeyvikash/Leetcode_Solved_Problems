class Solution {
public:
    #define ll long long
    
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum&1) return {};
        vector<ll>v;
        int num = 2;
        while(num<=finalSum)
        {
            v.push_back(num);
            finalSum-=num;
            num+=2;
        }
        int n = v.size();
        v[n-1] = v[n-1] + finalSum;
        return v;
    }
};