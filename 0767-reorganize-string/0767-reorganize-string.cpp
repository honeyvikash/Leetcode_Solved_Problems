class Solution {
public:
    string reorganizeString(string s) {
        map<char,int> m;
        for(auto &i:s)
        m[i]++;
        priority_queue<pair<int,char>> pq;
        for(auto &i:m)
        {
            pq.push({i.second,i.first});
        }
        string tmp = "";
        while(!pq.empty())
        {
            char c = pq.top().second;
            int fre = pq.top().first;
            fre--;
            pq.pop();
            tmp+=c;
            int flg = 0;
            if(pq.size()>0)
            {
                char c1 = pq.top().second;
                int fre1 = pq.top().first;
                fre1--;
                pq.pop();
                tmp+=c1;
                if(fre1>0)
                pq.push({fre1,c1});
                flg = 1;
            }
            if(fre>0)
            {
                if(!flg)
                return "";
                pq.push({fre,c});
            }
        }
        return tmp;
    }
};