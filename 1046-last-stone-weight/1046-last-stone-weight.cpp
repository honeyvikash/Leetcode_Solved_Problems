class Solution {
public:
    int lastStoneWeight(vector<int>& s) {
        priority_queue<int>p(s.begin(),s.end());
        while(p.size()>1)
        {
            int y=p.top();
            p.pop();
            int x=p.top();
            p.pop();
            if(y!=x)p.push(y-x);
        }
        return p.empty()?0:p.top();

    }
};