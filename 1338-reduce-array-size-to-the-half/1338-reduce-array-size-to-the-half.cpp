class Solution {
public:
   int minSetSize(vector<int> &arr){

        int n = arr.size();
        int half = ceil(n / 2.0);

        map<int, int> mpp;
        for (auto x: arr)
        {
            mpp[x]++;
        }

        priority_queue<pair<int, int>> pq;
        for (auto x: mpp)
        {
            pq.push({ x.second,
                x.first });
        }

        int count = 0;
        while (!pq.empty())
        {
            auto x = pq.top();
            pq.pop();
            count++;
            n -= x.first;
            if (n <= half)
            {
                break;
            }
        }
        return count;
    }
};