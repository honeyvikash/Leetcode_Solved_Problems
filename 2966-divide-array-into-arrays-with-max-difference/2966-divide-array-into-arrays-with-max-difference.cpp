class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            vector<int>tmp;
            while(i<n && cnt<3)
            {
                tmp.push_back(nums[i]);
                cnt++;
                i++;
            }
            ans.push_back(tmp);
            if(cnt==3)
            {
                cnt = 0;
                i--;
            }
        }
        for(auto &i:ans)
        {
            if(i[2]-i[0]>k)
            return {};
        }
        return ans;
    }
};