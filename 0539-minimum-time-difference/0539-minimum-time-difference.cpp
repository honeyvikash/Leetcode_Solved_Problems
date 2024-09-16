class Solution {
public:
    int timeDiff(string& t1, string& t2)
    {
        int minutes1 = stoi(t1.substr(0, 2))*60;
        minutes1 += stoi(t1.substr(3, 2));
        int minutes2 = stoi(t2.substr(0, 2))*60;
        minutes2 += stoi(t2.substr(3, 2));
        return min(minutes2-minutes1, minutes1+1440-minutes2);
    }
    int findMinDifference(vector<string>& t) {
        sort(t.begin(), t.end());
        int minDifference = INT_MAX;
        for (int i=0; i<t.size()-1; i++) {
            minDifference = min(minDifference, timeDiff(t[i], t[i+1]));
        }
        minDifference = min(minDifference, timeDiff(t[0], t.back()));
        return minDifference; 
    }
};