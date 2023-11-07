class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int time = 0;
        int n = dist.size();
        vector<int>tim(n);
        for(int i=0;i<n;i++)
        {
            tim[i] = ceil((double)dist[i]/speed[i]);
        }
        sort(tim.begin(),tim.end());
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            if(time<tim[i])
            {
                cnt++;
                time++;
            }
            else
            break;
        }
        return cnt;
    }
};