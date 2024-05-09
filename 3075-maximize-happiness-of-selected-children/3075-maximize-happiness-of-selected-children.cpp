class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, long long k) {
        long long n = happiness.size();
        sort(happiness.begin(),happiness.end(),greater<int>());
        long long ans=0;
        long long less = 0;
        for(int i=0; i<min(k,n); i++,less++)
        {
            if(happiness[i]<1+less) break;
            ans+=(long long)happiness[i]-less;           
        }
        return ans;
    }
};