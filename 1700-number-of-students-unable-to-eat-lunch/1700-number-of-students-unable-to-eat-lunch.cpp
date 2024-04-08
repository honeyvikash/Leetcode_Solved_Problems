class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& s) {
        queue<int>q;
        for(auto i:students)q.push(i);
        int j=0;
        int cnt = 0;
        while(j<s.size() && cnt<=500)
        {
            if(s[j]==q.front())
            {
                q.pop();
                j++;
            }
            else
            {
                auto tmp = q.front();
                q.pop();
                q.push(tmp);
            }
            cnt++;
        }
        return s.size()-j;
        }
};