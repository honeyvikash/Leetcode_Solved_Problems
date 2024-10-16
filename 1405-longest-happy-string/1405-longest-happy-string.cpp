class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        // hold result string
        string result = "";

        // track max count of char
        priority_queue<pair<int, char>> pq;
        if(a > 0) pq.push({a, 'a'});
        if(b > 0) pq.push({b, 'b'});
        if(c > 0) pq.push({c, 'c'});

        // now form longest string
        while(!pq.empty()) {
            int count = pq.top().first;
            char ch = pq.top().second;
            pq.pop();

            int size = result.size();
            if(size >= 2 && result[size-1] == ch && result[size-2] == ch) {
                if(pq.empty()) break;
                int tCount = pq.top().first;
                int tCh = pq.top().second;
                pq.pop();

                result.push_back(tCh);
                tCount -= 1;

                if(tCount > 0) pq.push({tCount, tCh});
                pq.push({count, ch});
            }
            else {
                result.push_back(ch);
                count -= 1;

                if(count > 0) pq.push({count, ch});
            }
        }

        return result;
    }
};