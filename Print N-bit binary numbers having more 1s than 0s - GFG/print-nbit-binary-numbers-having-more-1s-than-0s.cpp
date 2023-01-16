//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    void solve(int one,int zero,int n,string &op, vector<string>&v)
    {
        if(n==0)
        {
            v.push_back(op);
            return;
        }
        // as choice of 1 is available always so
        string op1=op;
        op1.push_back('1');
        solve(one+1,zero,n-1,op1,v);
        // for the choice of 0
        if(one>zero)
        {
            string op2=op;
            op2.push_back('0');
            solve(one,zero+1,n-1,op2,v);
        }
        return;
    }
	vector<string> NBitBinary(int n)
	{
	    vector<string>v;
	    string op="";
	    int one=0,zero=0;
	    solve(one,zero,n,op,v);
	    return v;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends