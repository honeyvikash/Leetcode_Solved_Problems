class Solution {
public:
    int convertTime(string current, string correct) {
        int ans = 0;
        int curr = (stoi(correct.substr(0,2)) - stoi(current.substr(0,2))) * 60
                + (stoi(correct.substr(3,2)) - stoi(current.substr(3,2)));
        while (curr > 0){
            if (curr >= 60)
                curr -= 60;
            else if (curr >= 15)
                curr -= 15;
            else if (curr >= 5)
                curr -= 5;
            else if (curr >= 1)
                curr -= 1;
            ans++;
        }
        return ans;
    }
};