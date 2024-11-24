class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int cntNeg = 0, minAbsNum = 1e9;
        long long int sum = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cntNeg += matrix[i][j]<0?1:0;
                minAbsNum = min(minAbsNum,abs(matrix[i][j]));
                sum += abs(matrix[i][j]);
            }
        }
        // if number of -ve number is even then all can be converted into +ve
        if(cntNeg%2 == 0) return sum;
        return sum - 2*1LL*minAbsNum;
    }
};