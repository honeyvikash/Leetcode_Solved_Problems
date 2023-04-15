class Solution {
    vector<vector<int>> memo;
public:
    int helper(vector<vector<int>> &piles,int limit,int ind){
        // cout<<limit<<" "<<ind<<"\n";
        if( 0==limit || ind==piles.size() ) return 0;
        if( -1!=memo[ind][limit] )  return memo[ind][limit];
        memo[ind][limit] = 0;
        
        int temp_limit = limit;
        int sum = 0;
        int ans = 0;
        ans = helper(piles,limit,ind+1);
        for(auto val : piles[ind] ){
            sum += val;
            limit -= 1;
            if( 0==limit ){
                return memo[ind][temp_limit] = max(ans,sum);
            }
            ans = max(ans,helper(piles,limit,ind+1)+sum);
        }
        // cout<<ind<<" "<<ans<<"\n";
        return memo[ind][temp_limit] = ans;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int len = piles.size();
        memo = vector<vector<int>> (len,vector<int>(k+1,-1));
        return helper(piles,k,0);
    }
};