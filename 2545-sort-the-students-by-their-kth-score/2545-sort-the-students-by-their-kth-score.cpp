class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        map<int,vector<int>> m;
        int n = score.size();
        for(int i=0;i<n;i++)
        {
            m[score[i][k]]=score[i];
        }
        score.clear();
        for(auto &i:m)
        {
            score.push_back(i.second);
        }
        reverse(score.begin(),score.end());
        return score;
    }
};