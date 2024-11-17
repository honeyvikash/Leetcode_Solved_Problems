class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
       int minL=INT_MAX;
       deque<pair<long long, int>>dq;
       long long sum=0;
       for(int r=0; r<nums.size(); r++){
            sum+=nums[r];
            if(sum>=k)
                minL= min(minL, r+1);
            //find minvalid window ending at r

            while(!dq.empty() && sum-dq.back().first>=k){
                auto [prefix, ind] = dq.back();
                dq.pop_back();
                minL= min(minL, r-ind);

            }
            while(!dq.empty() && dq.front().first>=sum)
                dq.pop_front();
            dq.push_front({sum, r});

       }
        return  minL==INT_MAX? -1 : minL;
    }
};