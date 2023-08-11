//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
//   int dp[1000][1000];
    // int solve(int idx,int amount,int coins[],int N)
    // {
    //     if(amount==0)
    //         return 1;
    //     if(amount<0 || idx>=N)
    //         return 0;
    //     if(dp[idx][amount]!=-1) return dp[idx][amount];
            
    //     int tak1 = 0,tak2 = 0;
        
    //     if(amount-coins[idx]>=0)
    //     {tak1 = solve(idx,amount-coins[idx],coins,N);}
        
        
    //     tak2 = solve(idx+1,amount,coins,N);
    //     return dp[idx][amount] = tak1+tak2;  
    // }
    long long int count(int coins[], int n, int sum) {
        vector<long long>dp(sum+1,0);
        dp[0]=1;
        for(int i=0;i<n;i++)
        {
            for(int j=coins[i];j<=sum;j++)
            {
                dp[j]+=dp[j-coins[i]];
            }
            
        }
        return dp[sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends