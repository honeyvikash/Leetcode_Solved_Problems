class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& p, int k) {
        vector<vector<int>>ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;   
        for(int i=0;i<p.size();i++)
        {
            int dis= (p[i][0]*p[i][0]) + (p[i][1]*p[i][1]) ;
            pq.push({dis,i});
        }
        while(k--)
        {
            ans.push_back(p[pq.top().second]);
            pq.pop();
        }
        return ans;
    }
};