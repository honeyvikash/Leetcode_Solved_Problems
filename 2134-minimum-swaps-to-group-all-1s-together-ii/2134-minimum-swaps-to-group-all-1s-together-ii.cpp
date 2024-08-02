class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        int total=0;
        for(int i=0;i<n;i++)
        {
            total += (nums[i]==1);
        }

        vector<int> temp = nums;
        temp.insert(temp.end(),nums.begin(),nums.end());

        int mini=0;
        int cnt=0;
        int i=0,j=0;
        while( j<(2*n) )
        {
            while(j<total)
            {
                if(temp[j]==0)
                {
                    cnt++;
                }
                mini=cnt;
                
                j++;
            }
            cnt += (temp[j]==0);
            cnt -= (temp[i]==0);
            i++;
            j++;
            mini = min(mini,cnt);
        }

        return mini;
    }
};