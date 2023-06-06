class Solution {
public:
    void merge(vector<int>& a1, int m, vector<int>& a2, int n) {
        int j=0;
        for(int i=m;i<n+m;i++)
        {
            if(a1[i]==0)
            {
                a1[i]=a2[j++];
            }
        }
        sort(a1.begin(),a1.end());
    }
};