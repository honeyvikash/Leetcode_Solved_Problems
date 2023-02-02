//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int dp[1001][1001];
    
    int knap(int W,int wt[],int val[],int n)
    {
       if( W==0 || n==0)return 0;

       if(dp[n-1][W]!=-1)
       {
           return dp[n-1][W];
       }
       if(wt[n-1]>W)
       {
             dp[n-1][W]=knap(W,wt,val,n-1);
            return dp[n-1][W];
       }
       else
       {
           dp[n-1][W]=max(val[n-1]+knap(W-wt[n-1],wt,val,n-1),knap(W,wt,val,n-1));
            return dp[n-1][W];
       }   
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       memset(dp,-1,sizeof(dp));
       return knap(W,wt,val,n);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends