class Solution {
public:
    int dp[302][302];
    int solve(vector<int>& arr , int i , int j){
        if(i>=j)
        return 0;
        if(dp[i][j]!=-1) return dp[i][j];
          
        int mini=INT_MIN;
        for (int k=i;k<=j-1;k++)
        {
            int temp=solve(arr,i,k)+solve(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]);
            mini=max(temp,mini);
        }
        return dp[i][j]=mini;
    }
    int maxCoins(vector<int>& nums) {
         int nn=nums.size();
         memset(dp,-1,sizeof(dp));
         vector<int>arr(nn+2);
         int n=arr.size();
         arr[0]=1;
         arr[n-1]=1;
        for(int i = 1;i<=nn;i++)
        {
            arr[i]=nums[i-1];   
        }
        return solve(arr,1,n-1);
        
    }
};