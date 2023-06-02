class Solution {
public:
    vector<int> leftRightDifference(vector<int>& a) {
        int n = a.size();
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            int aa = accumulate(a.begin(),a.begin()+i,0);
            int bb = accumulate(a.begin()+i+1,a.end(),0);
            int tmp = abs(aa-bb);
            ans.push_back(tmp);
        }
        return ans;
        
    }
};