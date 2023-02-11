//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std; 

// } Driver Code Ends
class Solution{
public:
    int onesComplement(int num){
        int x = log2(num) + 1;

        // Considering number to be 32 bit integer;
        bitset<32> b(num);
        
        // reversing the bits one by one
        for (int i = 0; i < x; i++)
            b.flip(i);
        
        // converting bitset to number
        return b.to_ulong();
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        Solution ob;
        cout<<ob.onesComplement(n)<<"\n";
    }
}
// } Driver Code Ends