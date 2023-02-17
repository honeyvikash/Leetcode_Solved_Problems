//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long solve(int N, int K, vector<long long> GeekNum) {
        // code here
          vector<long long> v;

        long long i=0,s=0,j=0;

        if(N<=K) return GeekNum[N-1];

        while(i<K){

            v.push_back(GeekNum[i]);

            s+=GeekNum[i];

            i++;

        }

        while(i<N){

            v.push_back(s);

            s+=v[i];

            s-=v[j];

            j++;

            i++;

        }

        return v[N-1];
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<long long> GeekNum(K);

        for (int i = 0; i < K; i++) cin >> GeekNum[i];

        Solution ob;
        cout << ob.solve(N, K, GeekNum) << "\n";
    }
    return 0;
}

// } Driver Code Ends