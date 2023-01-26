class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> temp(1001,0);
        for(auto &val : trips){
            temp[val[1]] += val[0];
            temp[val[2]] -= val[0];
        }
        for(int i=0 ; i<temp.size() && capacity>=0 ; i++){
            capacity -= temp[i];
        }
        return capacity>=0;
    }
};