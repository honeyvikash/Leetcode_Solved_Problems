class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        priority_queue<int>pq(nums.begin(), nums.end());
        int ans=0;
        while(k--)
        {
            int temp=pq.top();
            ans+=(temp);
            pq.push(temp+1);
        }
        return ans;
    }
};
