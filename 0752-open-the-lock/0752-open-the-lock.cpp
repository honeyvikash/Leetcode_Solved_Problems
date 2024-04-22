class Solution {
public:
    int openLock(vector<string>& deadends, string target) {

        queue<string> q;
        unordered_set<string> visited(deadends.begin(), deadends.end());
        if (visited.find("0000") != visited.end()) return -1;
        q.push("0000");
        visited.insert("0000");

        int len = q.size();
        int nextQ = 0;
        int rank = 0;
        while (!q.empty()) 
        {
            string res = q.front();
            q.pop();
            len--;

            if (res == target) return rank;

            for (int i = 0; i < 4; i++) 
            {
                string temp = res;
                temp[i] = ((temp[i] - '0' + 1) % 10) + '0';
                if (visited.find(temp) == visited.end()) 
                {
                    visited.insert(temp);
                    q.push(temp);
                    nextQ++;
                }
                    
                temp = res;
                temp[i] = ((temp[i] - '0' - 1 + 10) % 10) + '0'; //edge
                if (visited.find(temp) == visited.end()) 
                {
                    visited.insert(temp);
                    q.push(temp);
                    nextQ++;
                }
            }

            if (len <= 0) 
            {
                len = nextQ;
                nextQ = 0;
                rank++;
            }
        }
        return -1;
    }
};