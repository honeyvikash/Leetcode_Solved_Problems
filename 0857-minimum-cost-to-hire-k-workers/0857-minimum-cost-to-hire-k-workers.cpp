class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        
        int n = quality.size();
        vector<pair<int,int>> pv(n,pair<int,int>());
        
        for(int i = 0 ; i < n ; ++i)
            pv[i] = {quality[i],wage[i]};

        sort(pv.begin(),pv.end(),[](const pair<int,int>& a,const pair<int,int>& b)
        {
            return (1.0*a.second)/a.first < (1.0*b.second)/b.first;
        });

        priority_queue<int> pq;
        long long sm = 0;
        for(int i = 0 ; i < k-1 ; ++i)
        {
            sm+=pv[i].first;
            pq.push(pv[i].first);
        }
        double ans = 1e18;
        for(int i = k-1 ; i < n ; ++i)
        {
            sm+=pv[i].first;
            pq.push(pv[i].first);
            if(pq.size()>k)
            {
                sm-=pq.top();
                pq.pop();
            }
            ans = min(ans,1.0*sm*pv[i].second/pv[i].first);
        }
        return ans;
    }
};