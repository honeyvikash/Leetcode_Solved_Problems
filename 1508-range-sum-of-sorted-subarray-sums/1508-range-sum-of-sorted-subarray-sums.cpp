class Solution {
public:
    int rangeSum(vector<int>& nums,int n,int left,int right) {
        vector<int>subArraySum;
        
        for(int i=0;i<nums.size();i++) 
        {
            int sum=0;
            for(int j=i;j<nums.size();j++) 
            {
                sum+=nums[j];
                subArraySum.push_back(sum);
            }
        }
        
        sort(subArraySum.begin(),subArraySum.end());
        
        long long mod=1000000007,sum=0;
        for(int i=left-1;i<right;i++) 
        {
            sum=(sum+subArraySum[i])%mod;
        }
        return sum;
    }
};