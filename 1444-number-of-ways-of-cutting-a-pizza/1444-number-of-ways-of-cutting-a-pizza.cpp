class Solution {
    int const MOD = 1e9+7;
    vector<vector<vector<int>>> memo;
public:
    int helper(vector<string> &pizza,int sr,int sc,int er,int ec,int k){
        if( er<sr || ec<sc )    return 0;
        if( -1!=memo[sr][sc][k] )   return memo[sr][sc][k];
        bool gotTheApple = false;
        if( 1==k ){
            for(int i=sr ; i<=er && (false==gotTheApple) ; i++){
                for(int j=sc ; j<=ec && (false==gotTheApple) ; j++){
                    gotTheApple |= 'A'==pizza[i][j];
                }
            }
            return memo[sr][sc][k] = gotTheApple;
        }
        
        int ans = 0;
        for(int i=sr ; i<=er ; i++){
            if( false==gotTheApple ){
                for(int j=sc ; j<=ec ; j++){
                    gotTheApple |= 'A'==pizza[i][j];
                    if( gotTheApple )   break;
                }
            }
            if( gotTheApple ){
                ans = ( (ans%MOD) + (helper(pizza,i+1,sc,er,ec,k-1)%MOD) )%MOD;
            }
        }
        gotTheApple = false;
        for(int i=sc ; i<=ec ; i++){
            if( false==gotTheApple ){
                for(int j=sr ; j<=er ; j++){
                    gotTheApple |= 'A'==pizza[j][i];
                    if( gotTheApple )   break;
                }
            }
            if( gotTheApple )
                ans = ( (ans%MOD) + (helper(pizza,sr,i+1,er,ec,k-1)%MOD) )%MOD;
        }
        return memo[sr][sc][k] = ans;
    }
    int ways(vector<string>& pizza, int k) {
        int row = pizza.size();
        int col = pizza[0].size();
        memo = vector<vector<vector<int>>>(row,vector<vector<int>>(col,vector<int>(k+1,-1)));
        return helper(pizza,0,0,row-1,col-1,k);
    }
};