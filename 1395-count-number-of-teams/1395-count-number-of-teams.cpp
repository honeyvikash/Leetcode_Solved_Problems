class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n=rating.size();
        int cnt=0;
        for(int j=1;j<n-1;j++)
        {
            int leftsmall=0,leftlarge=0,rightsmall=0,rightlarge=0;

            //leftpart
            for(int i=0;i<j;i++)
            {
                if(rating[i]<rating[j])
                {
                    leftsmall++;
                }
                else
                {
                    leftlarge++;
                }
            }
            // rightpart
            for(int i=j+1;i<n;i++)
            {
                if(rating[i]<rating[j])
                {
                    rightsmall++;
                }
                else
                {
                    rightlarge++;
                }
            }
            cnt += (leftsmall * rightlarge) + (rightsmall * leftlarge);
        }
        return cnt;
    }
};