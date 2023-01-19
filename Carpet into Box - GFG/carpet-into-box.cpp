//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int carpetBox(int A, int B, int C, int D){
        //code here
         int count=0;
        priority_queue<int>p,q;
        p.push(A);p.push(B);
        q.push(C);q.push(D);
        while(p.size()!=0)
        {
            int check=p.top();
            if(check<=q.top())
            {
                q.pop();
                p.pop();
            }           
            else
            {
                int val=p.top()/2;
                count++;
                p.pop();
                p.push(val);
            }
        }
        return count;
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int A,B,C,D;
        cin>>A>>B>>C>>D;
        
        Solution ob;

        int ans = ob.carpetBox(A,B,C,D);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends