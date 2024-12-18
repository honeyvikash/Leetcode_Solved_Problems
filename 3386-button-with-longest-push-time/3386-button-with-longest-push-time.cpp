class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        pair<int,int> max_val = {events[0][0], events[0][1]} ; 

        if (events.size() < 2) return max_val.first ; 
        
        for ( int i = 1 ; i <  events.size() ; i++){

            if ((max_val.second < events[i][1] - events[i-1][1] )||
                (max_val.second == events[i][1] - events[i-1][1]&& max_val.first > events[i][0])){
                    max_val = {events[i][0] , events[i][1] - events[i-1][1]};
            }
        }

        return max_val.first ; 
    }
};