//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> topK(vector<int>& nums, int k) {
       priority_queue<pair<int,int>>pq;
       unordered_map<int,int>m;
       for(auto x:nums)
       {
           m[x]++;
       }
       for(auto x:m)
       {
           pq.push({x.second,x.first});
       }
       vector<int>v;
    //   while(!pq.empty())
    //   {
    //         cout<<(pq.top()).first<<" "<<(pq.top()).second<<endl;
            
    //         pq.pop();
            
    //   }
       while(k--)
       {
           int tmp=(pq.top()).second;
           pq.pop();
           v.push_back(tmp);
       }
       return v;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends