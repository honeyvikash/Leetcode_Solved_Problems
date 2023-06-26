class Solution {
public:
    long long totalCost(vector<int>& cost, int k, int cand) {
        
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        
        int n = cost.size();
        int p1 = 0,p2 = n-1;
        int cnt1 = 0,cnt2 = 0;
        
        while(p1<=p2 && cnt1<cand && cnt2<cand)
        {
            if(cnt1<cand)
            {
                pq.push({cost[p1],p1,0});
                p1++;
                cnt1++;
            }
            if(cnt2<cand && p1<=p2) // yha pe bhi ye check lgan pdega p1<=p2
            {
                pq.push({cost[p2],p2,1});
                p2--;
                cnt2++;
            }
        }
        long long ans = 0;
        while(!pq.empty() && k>0)
        {
            int side = pq.top()[2];
            if(side==0)
            {
                ans+=pq.top()[0];
                pq.pop();
                if(p1<=p2)
                {
                    pq.push({cost[p1],p1,0});
                    p1++;
                }
            }
            if(side==1)
            {
                ans+=pq.top()[0];
                pq.pop();
                if(p2>=p1)
                {
                    pq.push({cost[p2],p2,1});
                    p2--;
                }
            }
            k--;
        }
        return ans;
    }
};