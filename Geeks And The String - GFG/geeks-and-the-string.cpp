//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string removePair(string s) {
        // code here
         string ans="";
        for(char &c: s){
            if(ans.length()==0)
              ans.push_back(c);
          else if(ans.back()==c)
            ans.pop_back();
          else
            ans.push_back(c);
        }
        return ans==""?"-1":ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends