//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        vector<char> m1;
        vector<char> m2;
        string res="";
        for(int i=0; i<n; i++)
        {
            if(str[i]>='a' && str[i]<='z')
            {
                m1.push_back(str[i]);
            }
            else
            {
                m2.push_back(str[i]);
            }
        }
        sort(m1.begin(),m1.end());
        sort(m2.begin(),m2.end());
        int j=0,k=0;
        for(int i=0; i<n; i++)
        {
            if(str[i]>='a' && str[i]<='z')
            {
                res+=m1[j];
                j++;
            }
            else
            {
                res+=m2[k];
                k++;
            }
        }
        return res;
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
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends