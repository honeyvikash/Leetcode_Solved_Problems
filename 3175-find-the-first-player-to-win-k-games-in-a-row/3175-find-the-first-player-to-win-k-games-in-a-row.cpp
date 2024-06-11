class Solution {
public:
    int findWinningPlayer(vector<int>& s, int k) {
        int n = s.size();
        deque<int> pq;

        for (int i = 1; i < n; i++) 
        {
            pq.push_back(i);
        }

        int ele = 0, w = 0;
        while (true) 
        {
            int num = pq.front();
            pq.pop_front();
            if (s[num] < s[ele]) 
            {
                w++; 
                pq.push_back(num); 
            }
            else
            {
                w = 1; 
                ele = num ;
                pq.push_back(ele) ;
            }

            if(w==k || w>=n-1) return ele ;
        }
        return 1;
    }
};