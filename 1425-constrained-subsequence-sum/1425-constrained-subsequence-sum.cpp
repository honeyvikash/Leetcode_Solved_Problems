class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        //Using dequeue :)
        int n = nums.size();
        deque<int> dq;
        int mx = nums[0];
        dq.push_back(0);

        for(int i = 1 ; i < n ; ++i)
        {
            nums[i] += max(0,nums[dq.front()]);
            mx = max(mx,nums[i]);

            while(!dq.empty() && nums[i]>=nums[dq.back()])
                dq.pop_back();

            dq.push_back(i);
            if(dq.front()==i-k)
                dq.pop_front();
        }
        return mx;
    }
};