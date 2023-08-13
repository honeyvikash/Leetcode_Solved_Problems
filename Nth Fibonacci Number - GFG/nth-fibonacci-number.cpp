//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  int mod = 1e9+7 ;
    int nthFibonacci(int n){
        long long int a = 0  , b = 1,c;
        long long int cnt = 1 ;
        if(n==1) return a ;
        else if(n==2) return b ;
        else
        {
            cnt = 2 ;
            while(cnt<=n)
            {
                c  = (a+b)%mod ;
                a = b ;
                b = c ;
                cnt++ ;
            }
        }
        return c ;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends