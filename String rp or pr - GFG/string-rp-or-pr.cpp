//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    long long f(int x,int y,string s,string res)
    {
        stack<char>st;
        long long ans=0;
        for(int i=0;i<s.size();i++)
        {
            if(st.size() && s[i]==res[1] && st.top()==res[0])
            {
                ans+=x;
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
        s="";
        while(!st.empty())
        {
            s+=st.top();
            st.pop();
            
        }
        for(int i=0;i<s.size();i++)
        {
            if(st.size() && s[i]==res[1] && st.top()==res[0])
            {
                ans+=y;
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
        return ans;
        
    }
    long long solve(int x,int y,string s){
      //code here
      if(x>y)return f(x,y,s,"pr");
      return f(y,x,s,"rp");
    }
};

//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int X,Y;
      cin>>X>>Y;
      string S;
      cin>>S;
      Solution obj;
      long long answer=obj.solve(X,Y,S);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends