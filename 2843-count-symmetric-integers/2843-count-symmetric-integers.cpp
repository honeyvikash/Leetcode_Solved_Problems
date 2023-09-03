class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        for(int i=low;i<=high;i++)
        {
            vector<int> tmp;
            int num = i;
            while(num)
            {
                tmp.push_back(num%10);
                num/=10;
            }
            if(tmp.size()%2!=0)
                continue;
            int sum1 = 0,sum2 =0;
            for(int j=0;j<tmp.size()/2;j++)
            {
                sum1+=tmp[j];
            }
            for(int j=tmp.size()/2;j<tmp.size();j++)
            {
                sum2+=tmp[j];
            }
            if(sum1==sum2)
                cnt++;
        }
        return cnt;
    }
};