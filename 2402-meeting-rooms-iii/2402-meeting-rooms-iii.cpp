class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& nums) {
        
        sort(nums.begin(),nums.end());

        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;

        priority_queue<int,vector<int>,greater<int>> av;

        for(int i = 0 ; i < n ; ++i)
            av.push(i);

        map<int,int> cnt;
        int ns = nums.size();
        int mx = 0;
        for(int i = 0 ; i < ns ; ++i)
        {

            while(!pq.empty() && pq.top().first<=nums[i][0])
            {
                av.push(pq.top().second);
                pq.pop();
            }

            int room;
            long long start , td = nums[i][1]-nums[i][0];
            if(av.empty())
            {
                start = pq.top().first;
                room  = pq.top().second;
                pq.pop();
            }
            else
            {
                start = nums[i][0];

                room = av.top();

                av.pop();
            } 
            cnt[room]++;
            mx = max(mx,cnt[room]);
            pq.push({start+td,room});
        }
        for(auto&[a,b]:cnt)
            if(b==mx)
                return a;
        return -1;
    }
};