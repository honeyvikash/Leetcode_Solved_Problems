//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    vector<string>ans;
  public:
  void solve(int i, string s, long sum, long prev, string &num, int target)
  {
      if (i == num.size()) 
      {
		if (sum == target) 
		{
			ans.push_back(s);
			return;
		}
	  }
	  
	  for(int j=i;j<num.size();j++)
	  {
	      if (j > i && num[i] == '0') break;
	      long long number = stol(num.substr(i, j - i + 1));
	      if (i == 0)
	      {
	          solve(j + 1, s + num.substr(i, j - i + 1), number, number, num, target);
	      }
	      
	      else 
	      {
				solve(j + 1, s + "+" + num.substr(i, j - i + 1), sum + number, number, num, target);
				solve(j + 1, s + "-" + num.substr(i, j - i + 1), sum - number, -number, num, target);
				solve(j + 1, s + "*" + num.substr(i, j - i + 1), sum - prev + prev * number, prev * number, num, target);
		  }
	  }
  }
    vector<string> addOperators(string num, int target) {
        string s="";
        solve(0,s,0,0,num,target);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int target;
        string S;
        cin >> S >> target;

        Solution obj;
        vector<string> ans = obj.addOperators(S, target);
        sort(ans.begin(), ans.end());
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends