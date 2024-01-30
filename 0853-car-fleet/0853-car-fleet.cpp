class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        int n = speed.size();
        vector<pair<int,double>> pv(n,pair<int,double>());

        for(int i = 0 ; i < n ; ++i)
            pv[i] = {position[i],speed[i]};

        sort(pv.begin(),pv.end());

        for(int i = 0 ; i < n ; ++i)
            pv[i].second = (target-pv[i].first)/pv[i].second;

        int ans = 0;
        double tmp = pv.back().second;
        int cnt = 1;
        for(int i = n-1 ; i >= 0 ; --i)
        {
            if(pv[i].second>tmp)
            {
                tmp = pv[i].second;
                cnt++;
            }
        }
        return cnt;
    }
};