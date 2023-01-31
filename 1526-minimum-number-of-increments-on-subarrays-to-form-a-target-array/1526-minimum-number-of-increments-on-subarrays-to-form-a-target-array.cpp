class Solution {
public:
    int minNumberOperations(vector<int>& t) {
        int ans = t[0];
        int temp=t[0];
        for(int i=1 ; i<t.size() ; i++)
        {
            if( temp<t[i] )
            {
                ans += t[i]-temp;
            }
            temp = t[i];
        }
        return ans;   
    }
};