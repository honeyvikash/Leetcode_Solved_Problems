//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int countRev (string s)
{
    stack<char>st;
    int ans = 0;
   
    
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='{')
        {
            st.push(s[i]);
        }
        else 
        {
            if(st.size()==0)
            {
                ans++;
                st.push('{');
            }
            else
            {
                st.pop();
            }
        }
    }
    if(st.size()%2!=0)return -1;
    int op = st.size()/2;
    return ans+op;
    
}