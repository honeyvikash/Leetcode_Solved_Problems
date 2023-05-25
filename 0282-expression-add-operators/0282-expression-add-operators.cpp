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