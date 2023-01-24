class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        priority_queue<pair<int,int>>p;
        for(int i=0;i<n;i++)
        {
            int cnt=count(mat[i].begin(),mat[i].end(),1);
            p.push({cnt,i});
            // imp to push this below condition as we need to store only k smallest ele
            if(p.size()>k)p.pop();
        }        
        vector<int>ans;
        while(k--)
        {
            ans.push_back(p.top().second);
            p.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};