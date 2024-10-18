class Solution {
    void f(int ind,int orr,int& count,int maxi,int n,vector<int>& nums){
        if(ind>=n){
            if(maxi==orr) count++;
            return ;
        }

        //pick
        int org=orr;
        orr|=nums[ind];
        f(ind+1,orr,count,maxi,n,nums);
        orr=org;

        //not pick
        f(ind+1,orr,count,maxi,n,nums);

    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxi=0;
        int count=0;
        for(auto i:nums){
            maxi|=i;
        }
        f(0,0,count,maxi,nums.size(),nums);
        return count;
    }
};