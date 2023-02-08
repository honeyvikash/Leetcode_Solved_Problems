class Solution {
public:
    int jump(vector<int>& a) {
        int jump=0;
        int crnt=0,dis=0;
        for(int i=0;i<a.size()-1;i++)
        {
            dis=max(dis,a[i]+i);
            if(i==crnt)
            {
                crnt=dis;
                jump++;
            }
        }
        return jump;
    }
};