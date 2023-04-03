class Solution {
public:
    int maximizeGreatness(vector<int>& a) {
        sort(a.begin(),a.end());
        int i = 0,j = 0,n=a.size();
        while(j<n)
        {
            if(a[j]>a[i])
            {
                i++;
                j++;
            }
            else j++;
        }
        return i;
    }
};