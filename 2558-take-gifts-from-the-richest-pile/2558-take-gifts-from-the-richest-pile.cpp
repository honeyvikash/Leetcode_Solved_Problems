class Solution {
public:
    long long pickGifts(vector<int>& g, int k) {
        priority_queue <int> pq(g.begin(),g.end());
        while(k--)
        {
            int p = pq.top();
            pq.pop();
            pq.push(floor(sqrt(p)));
        }
        long long sum=0;
        while(!pq.empty())
        {
            sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
};