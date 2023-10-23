class Solution {
public:
    vector<int> findIndices(vector<int>& a, int id, int vd) {
        vector<int> ans;
        int n = a.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(abs(i-j)>=id && abs(a[i]-a[j])>=vd)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                    break;
                }
            }
            if(ans.size()>0)
                break;
        }
        if(ans.size()==0)
            return {-1,-1};
        return ans;
    }
};