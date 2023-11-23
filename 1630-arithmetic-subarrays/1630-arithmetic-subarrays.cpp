class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for(int i = 0;i < l.size();i++)
        {
            vector<int>a(r[i] - l[i] + 1);
            int m = 0;
            for(int j = l[i];j <= r[i];j++)
            {
                a[m++] = nums[j];
            }    
            sort(a.begin(),a.end());
            int diff = a[1] - a[0];
            bool flag = true;
            for(int j = 0; j < m-1;j++)
            {
                if(diff != a[j+1] - a[j])
                {
                    ans.push_back(false);
                    flag = false;
                    break;
                }
            }
            if(flag) ans.push_back(true);
        }
        return ans;
    }
};