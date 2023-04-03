class comp{
    public:
        bool operator()(string &s2,string &s1)
        {
            if(s1.size()!=s2.size())  return s1.size()<s2.size();
            return s1<s2;
        }
};

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        // priority_queue<ll>pq;
        // for(auto &x:nums)
        // {
        //     ll p = stoll(x);
        //     pq.push(p);
        //     // cout<<"x:"<<x<<" ";
        // }
        // // cout<<endl;
        // int temp=k-1;
        // while(temp--)
        // {
        //     // cout<<pq.top()<<endl;
        //     pq.pop();
        // }
        // string kk = to_string(pq.top());
        // return kk;
        
        // So inshort ye question hai comparator ka
        
        priority_queue<string,vector<string>,comp>pq;
        for(auto &x:nums)
        {
            pq.push(x);
            if(pq.size()>k)pq.pop();
        }
        return pq.top();
    }
};