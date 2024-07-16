class Solution {
public:
    int minimumCost(int m, int n, vector<int>& h, vector<int>& v) {
        priority_queue<pair<int,int>>pq;
        for(auto it:h)pq.push({it,0});
        for(auto it:v)pq.push({it,1});
        
        int vcnt=0,hcnt=0;
        long long ans = 0;
        while(!pq.empty())
        {
            int cost = pq.top().first;
            int type = pq.top().second;
            pq.pop();
            if(type==0)
            {
                ans += ((vcnt+1)*cost);
                hcnt++;
            }
            else
            {
                ans += ((hcnt+1)*cost);
                vcnt++;
            }
        }
        return ans;
    }
};