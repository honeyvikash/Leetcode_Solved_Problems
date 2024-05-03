class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // int n=nums.size();
        // vector<int>v(n);
        // for(int i=0;i<n;i++)
        // {
        //    v[(i+k)%n]=nums[i];
        // }
        // nums=v;
        
        // 2nd Approach  
        int n=nums.size(); k%=n;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    
    }
};