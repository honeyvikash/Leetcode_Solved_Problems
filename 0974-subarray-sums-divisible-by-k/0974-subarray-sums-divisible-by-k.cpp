class Solution {
public:
    int subarraysDivByK(vector<int>& a, int k) {
        unordered_map<int,int>m;
        int sum_of_remainders = 0, ans=0;
        m[0]=1;
        for(auto &x:a)
        {
            sum_of_remainders=((sum_of_remainders+x)%k+k)%k;// k is added to handle -ve wale
            m[sum_of_remainders]++;
            if(m[sum_of_remainders]>1)
            {
                ans+=m[sum_of_remainders]-1;
            }
        }
        return ans;
    }
};