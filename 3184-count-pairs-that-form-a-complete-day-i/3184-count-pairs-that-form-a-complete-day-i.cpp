class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        
        int ans = 0;
        
        map<int,int> mp;
        
        for(auto&a:hours){
            mp[a%24]++;
        }
        
        for(auto&[a,b]:mp)
        {
            if(a==0 || a==12){
                ans += b*(b-1);
            }
            else if(mp[(24-a)]>0)
                ans += mp[24-a]*b;
        }
        
        return ans/2;
    }
};