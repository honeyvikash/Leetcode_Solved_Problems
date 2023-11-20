class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int lg=0,lm=0,lp=0;
        int gc=0,mc=0,pc=0;
        vector<long long>presum(travel.size()+1);
        presum.push_back(0);
        for(int i=1;i<=travel.size();i++)
        {
            presum[i]=presum[i-1]+travel[i-1];
        }
        for(int i=0;i<garbage.size();i++)
        {
            string temp=garbage[i];
            for(auto x:temp)
            {
                if(x=='M')
                {
                    mc+=1;
                    lm=i;
                }
                else if(x=='P')
                {
                    pc+=1;
                    lp=i;
                }
                else
                {
                    gc+=1;
                    lg=i;
                }
            }
        }
        int ans=0;
        if(mc)  ans+=presum[lm]+mc;
        if(gc)  ans+=presum[lg]+gc;
        if(pc)  ans+=presum[lp]+pc;
        return ans;
    }
};