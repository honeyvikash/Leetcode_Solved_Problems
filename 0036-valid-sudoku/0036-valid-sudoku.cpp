class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<string>s;
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                 if(board[i][j]!='.')
                 {
                     string t1="row"+to_string(i)+board[i][j];
                     string t2="col"+to_string(j)+board[i][j];
                     string t3="box"+to_string((i/3)*3 +(j/3))+board[i][j];
                     
                     if(s.find(t1)==s.end()  && s.find(t2) ==s.end()  && s.find(t3) == s.end() )
                     {
                          s.insert(t1);
                          s.insert(t2);
                          s.insert(t3);
                     }
                     else return false;
                 }
            }
        }
        return true;
    }
};