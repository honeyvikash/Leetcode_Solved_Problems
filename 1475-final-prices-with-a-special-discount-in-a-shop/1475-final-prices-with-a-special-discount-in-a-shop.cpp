class Solution {
public:
    vector<int> finalPrices(vector<int>& p) {
        stack<int>s;
        int n=p.size();
        vector<int>v(n);
        
        s.push(0);
        for(int i=n-1;i>=0;i--)
        {
            int curr=p[i];
            while(curr<s.top())
            {
                s.pop();
            }
            v[i]=curr-s.top();
            s.push(curr);
        }
        return v;
    }   
};