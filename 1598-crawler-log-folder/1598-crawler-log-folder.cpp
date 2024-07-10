class Solution {
public:
    int minOperations(vector<string>& logs) {
        
        int ans=0;
        for(auto&a:logs)
        {
            if(a=="../")
            {
                if(ans>0)ans--;
            }
            else if(a!="./")
                ans++;
        }
        return ans;
    }
};