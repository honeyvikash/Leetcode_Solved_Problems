class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        vector<int> v1(deck.size());
        sort(deck.begin(),deck.end());
        deque<int> dq;
        for (int i=0;i<deck.size();i++)
        {
            dq.push_back(i);
        }
        int i=0;
        while(dq.empty()==0)
        {
            int curr_idx=dq.front();
            dq.pop_front();
            int b=dq.front();
            dq.push_back(b);
            dq.pop_front();
            v1[curr_idx]=deck[i];
            i++;
        }
        return v1;
    }
};