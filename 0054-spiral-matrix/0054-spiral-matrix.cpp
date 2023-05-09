class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int sr = 0,sc = 0,er = matrix.size()-1,ec = matrix[0].size()-1,cnt = matrix.size()*matrix[0].size();
        vector< int > ans;
        while(cnt>0){
            int i = sc;
            while( i<=ec && cnt>0 ) cout<<i<<" ",
                ans.push_back(matrix[sr][i++]),cnt--;
            sr += 1;
            i = sr;
            while( i<=er && cnt>0 ) cout<<i<<" ",
                ans.push_back(matrix[i++][ec]),cnt--;
            ec -= 1;
            i = ec;
            while( i>=sc && cnt>0 ) cout<<i<<" ",
                ans.push_back(matrix[er][i--]),cnt--;
            er -= 1;
            i = er;
            while( i>=sr && cnt>0 ) cout<<i<<" ",
                ans.push_back(matrix[i--][sc]),cnt--;
            sc += 1;
        }
        return ans;
    }
};