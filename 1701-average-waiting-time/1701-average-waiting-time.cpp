class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& c) {
        double totalTime = 0 ;
        int n = c.size() ;

        long long sum = 0 ;
        long long tim = c[0][0]+c[0][1] ;
        sum+=c[0][1] ;
        cout<<sum<<" ";

        for(int i=1 ; i<n ; i++)
        {
            int waitedForArrival = max((long long)0,(long long)tim-c[i][0]) ;
            sum+=(waitedForArrival+c[i][1]);

            if(tim>c[i][0]) tim+=c[i][1] ;
            else {
            tim = c[i][0];
            tim+=c[i][1];
            }

            cout<<sum<<" ";
        }

        double avg = (double) sum / (double) n ;
        return avg ;
    }
};