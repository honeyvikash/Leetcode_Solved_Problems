class Solution {
public:
    class cmp
    {
        unordered_map<int,int> & mp;
        public:
        cmp(unordered_map<int,int> & m):mp(m){}
        bool operator()(int&i1, int&i2)
        {
            if(mp[i1]!=mp[i2])
            return mp[i1]<mp[i2];
            else
            return i1>i2;
        }
    };
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto it : nums)
        mp[it]++;
        sort(nums.begin(),nums.end(),cmp(mp));
        return nums;
    }
};