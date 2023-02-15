class Solution {
public:
    vector<int> ans;
    vector<int> solve(vector<int> a,int k)
    {
         int i=a.size()-1;
         int carry=0;
         while(i>=0)
         {
             int d=k%10;
             int sum=carry+a[i]+d;
             carry=sum/10;
             k=k/10;
             sum=sum%10;
             ans.push_back(sum);
             i--;
         }
        while(k!=0)
        {
            int d=k%10;
            int s=d+carry;
            carry=s/10;
            s=s%10;
            ans.push_back(s);
            k=k/10;
        }
        if(carry!=0)
        {
            ans.push_back(carry);
        }
          reverse(ans.begin(),ans.end());
          return ans;
      }
    vector<int> addToArrayForm(vector<int>& a, int k) {
        return solve(a,k);
    }
};