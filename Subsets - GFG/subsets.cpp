//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    void solve (vector<int>& A,vector<vector<int>> &vc,vector<int> temp,int index){
        if(index >=A.size())
        {
            // collect the subsets
            vc.push_back(temp);
            return;
        }
        // excluding the values
        solve(A,vc,temp,index+1);
        
        // including the value
        temp.push_back(A[index]);
        
        solve(A,vc,temp,index+1);
    }
    vector<vector<int> > subsets(vector<int>& A)
    {
        vector<vector<int>>vc;
        vector<int> temp;
        int index=0;
        solve(A,vc,temp,index);
        sort(vc.begin(),vc.end());
        return vc;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n, x;
		cin >> n;

		vector<int> array;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			array.push_back(x);
		}
        
        
        Solution ob;
		vector<vector<int> > res = ob.subsets(array);

		// Print result
		for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << endl;
		}

		
	}

	return 0;
}
// } Driver Code Ends