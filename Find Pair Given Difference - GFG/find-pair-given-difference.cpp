//{ Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}
// } Driver Code Ends

int bs(int arr[],int size,int w){
    
    int s=0;
    int e=size-1;
    
   
    while(s<=e){
        int mid =s+(e-s)/2;
        if (arr[mid]==w){
            return mid;
        }
        else if (w>arr[mid]) 
        {
            s=mid+1;
        }
        else {
            e=mid-1;
        }
        
        // mid =(s+e)/2;
    }
    
    return -1;
}

bool findPair(int arr[], int size, int n){
    //code
     sort(arr,arr+size);
     int count=0;
  
    for (int i=0;i<size;i++)
    {
      int w=abs(n-arr[i]);
    //   if(w==arr[i])return false;
      if (bs(arr,size,w)!=-1  && bs(arr,size,w)!=i)
      {
          count++;
      }
    // cout<<w<<endl;
    // if(binary_search(arr,arr+size,w))
    //   return true;
     }
  
  if (count>0){
      return true;
  }
  return false;
    
}