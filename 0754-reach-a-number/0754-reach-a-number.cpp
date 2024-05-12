class Solution {
public:
    int reachNumber(int tar) {
        tar = abs(tar);
        int natural=1,sum=0,cnt=0;
        while(sum<tar)
        {
            sum+=natural;
            natural++;
            cnt++;
        }
        while((sum-tar)%2!=0)
        {
            cnt++;
            sum+=natural;
            natural++;
        }
        return cnt;
    }
};