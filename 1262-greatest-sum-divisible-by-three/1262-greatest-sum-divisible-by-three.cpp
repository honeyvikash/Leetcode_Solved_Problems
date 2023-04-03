class Solution {
public:
#define ll long long
#define all(a) (a).begin(), (a).end()
    
    int maxSumDivThree(vector<int>& a) {
        
        // vector<int>v1;
        // vector<int>v2;
        
        // ll sum = accumulate(all(a),0ll);
        // // if(a.size()==1)
        // for(auto &x:a)
        // {
        //     if(x%3==1)
        //     {
        //         v1.push_back(x);
        //     }
        //     else if(x%3==2)
        //     {
        //         v2.push_back(x);
        //     }
        // }
        // sort(all(v1),greater<int>());
        // sort(all(v2),greater<int>());
        
        // if(sum%3==1)
        // {
        //     int k1=0,k2=0,k;
        //     if(v1.size()!=0)
        //     {
        //         k1 = v1.back();
        //         v1.pop_back();
        //     }
        //     if(v2.size()>=2)
        //     {
        //         int p1=v2.back(),p2=0;
        //         v2.pop_back();
        //         if(v2.size()!=0)
        //         {
        //             p2=v2.back();
        //             v2.pop_back();
        //         }
        //         k2= p1+p2;
        //     }
        //     if(v2.size()<2 && v1.size()!=0)k=k1;
        //     else k= min(k1,k2);
        //     return sum-k;
        // }
        // else if(sum%3==2)
        // {
        //     int k1=0,k2=0,k;
        //     if(v2.size()!=0)
        //     {
        //         k1 = v2.back();
        //         v2.pop_back();
        //     }
        //     if(v1.size()>=2)
        //     {
        //         int p1=v1.back(),p2=0;
        //         v1.pop_back();
        //         if(v1.size()!=0)
        //         {
        //             p2=v1.back();
        //             v1.pop_back();
        //         }
        //         k2= p1+p2;
        //     }
        //     if(v1.size()<2 && v2.size()!=0)k=k1;
        //     else k= min(k1,k2);
        //     return sum-k;
        // }
        // return sum;

        vector<vector<int>>v(3);
        
        ll sum = accumulate(all(a),0ll);

        if(sum%3==0)return sum;
        
        for(auto &x:a)
        {
            v[x%3].push_back(x);
        }

        for(auto &x:v)
        {
            sort(all(x));
        }

        

        if(sum%3==1)
        {
            int k1=0,k2=0,k=0;
            if(v[1].size()>0)
            {
                k1=sum-v[1][0];
            }
            if(v[2].size()>=2)
            {
                int p1=v[2][0];
                int p2=v[2][1];
                k2=sum-(p1+p2);
            }
            return max(k1,k2);
        }

        else
        {
            int k1=0,k2=0,k=0;
            if(v[2].size()>0)
            {
                k1=sum-v[2][0];
            }
            if(v[1].size()>=2)
            {
                int p1=v[1][0];
                int p2=v[1][1];
                k2=sum-(p1+p2);
            }
            return max(k1,k2);
        }

    }
};