class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
        //sliding window se to nhi hoga baat saaf hai
        unordered_map<int, int> m;
        m[0] = 1;
        int sum = 0, ans = 0;
        for(auto  &i : a){
            sum += i;
            if(m.count(sum-k)) ans += m[sum-k];
            m[sum]++;
        }
        return ans;
    }
};