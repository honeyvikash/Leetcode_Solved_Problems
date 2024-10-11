class Compare{
public:
    bool operator()(int &a,int &b){
        return a>b;
    }
};

class Compare2{
    public:
    bool operator()(pair<int,pair<int,int>> &a,pair<int,pair<int,int>> &b){
        return a.second.second >= b.second.second;
    }
};

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,Compare2> q;
        int target= times[targetFriend][0];
        sort(times.begin(),times.end());
        int latest=0;
        priority_queue<int,vector<int>,Compare> minHeap; 
        minHeap.push(0);

        for(auto &time:times){
            int a=time[0],b=time[1];
            if(q.empty()){
                cout<<"start ";
                q.push({minHeap.top(),{a,b}});
                if(target==a) return minHeap.top();
                minHeap.pop();
            }
            else{
                auto [chair,slot]= q.top();
                while(slot.second<=a){
                    q.pop();
                    minHeap.push(chair);
                    if(q.empty()) break;
                    chair= q.top().first;
                    slot= q.top().second;
                }
                if(minHeap.empty()){
                    cout<<"all_full_"<<latest+1<<" ";
                    q.push({++latest,{a,b}});
                    if(target==a) return latest;
                }
                else{
                    cout<<minHeap.top()<<" ";
                    q.push({minHeap.top(),{a,b}});
                    if(target==a) return minHeap.top();
                    minHeap.pop();
                }
            }
        }

        return 0;
    }
};