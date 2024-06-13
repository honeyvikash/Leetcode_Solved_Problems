class Solution {
public:
    int minMovesToSeat(vector<int>& seat, vector<int>& bacha) {
        sort(seat.begin(),seat.end());
        sort(bacha.begin(),bacha.end());
        int sum=0;
        for(int i=0;i<seat.size();i++)
        {
            sum+=abs(seat[i]-bacha[i]);
        }
        return sum;
    }

};