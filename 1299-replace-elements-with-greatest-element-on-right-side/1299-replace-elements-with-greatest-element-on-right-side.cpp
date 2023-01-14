class Solution {
public:
    vector<int> replaceElements(vector<int>& a) {
        int n=a.size();
        int maxi=-1;
        for(int i=n-1;i>=0;i--)
        {
            int p=a[i];
            a[i]=maxi;
            maxi=max(maxi,p);
        }
        return a;
    }
};