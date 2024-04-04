class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& op) {
        int n=nums.size();
        int m=op.size();
        unordered_map<int,int> mp;

        for(int i=0;i<n;i++)
        {
            mp[nums[i]]=i;
        }

        for(int i=0;i<m;i++)
        {
            nums[mp[op[i][0]]]=op[i][1];
            mp[op[i][1]]=mp[op[i][0]];
        }    

        return nums;
    }
};