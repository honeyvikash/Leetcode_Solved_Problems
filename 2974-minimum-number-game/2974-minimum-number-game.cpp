class Solution {
public:
    vector<int> numberGame(vector<int>& a) {
        vector<int>ans;
        int n = a.size();
        sort(a.begin(),a.end());
        for(int i=0;i<n-1;i+=2)
        {
            int alice = a[i];
            int bob = a[i+1];
            ans.push_back(bob);
            ans.push_back(alice);
        }
        return ans;
    }
};