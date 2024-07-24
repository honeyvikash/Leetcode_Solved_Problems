class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        unordered_map<int, int>mpp;
        for(auto it:nums) 
        {
            if (it==0) 
            {
                mpp[it]=mapping[0];
                continue;
            }
            int mappedNum=0, placeValue=1;
            int temp=it;
            while(temp) 
            {
                mappedNum+=placeValue*mapping[temp%10];
                temp/=10;
                placeValue*=10;
            }
            mpp[it]=mappedNum;
        }
        sort(nums.begin(), nums.end(), [&mpp](int a,int b) 
        {
            return mpp[a] < mpp[b];
        });
        return nums;
    }
};