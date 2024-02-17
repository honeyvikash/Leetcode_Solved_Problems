class Solution {
public:
    int furthestBuilding(vector<int>& arr, int b, int l) {
        
        int n = arr.size();
        priority_queue<long long,vector<long long>,greater<long long>> pq;

        long long sm = 0,ts=0,i;
        for(i = 0 ; i < n-1 ; ++i)
        {
            long long da = arr[i+1]-arr[i];
            if(da<=0)
                continue;
            else
            {
                ts += da;

                pq.push({da});
                sm+=da;

                if(pq.size()>l)
                {
                    sm-=pq.top();
                    pq.pop();
                }

                if(ts-sm>b)
                {
                    break;
                }
            }
        }
        return i;

    }
};