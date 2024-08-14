class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        vector<int> dist;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int low=0,high=nums[n-1]-nums[0];

        while(low<high){
            int mid = (low + high)/2;
            int cnt=0,left=0;

            for(int right=0;right<n;right++){
                while( nums[right]-nums[left] > mid ){
                    left++;
                }
                cnt += right-left;
            }

            if(cnt >= k){
                high=mid;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};