class Solution {
public:
    int numberOfSubarrays(vector<int>& a, int k) {
        //0 and 1 then the que is subarray sum  = k
        int n = a.size();
        vector<int> v;
        for(auto x: a){
            if(x%2==0)
            {
                v.push_back(0);
            }
            else
            {
                v.push_back(1);
            }
        }

        int currSum = 0;
        int count = 0;
        unordered_map<int , int> m;
        for(int i = 0 ; i<n; i++)
        {
            currSum+=v[i];
            if(currSum==k) count++;
            
            if(m.find(currSum-k)!=m.end())
            {
                count+=m[currSum-k];
            }
            m[currSum]+=1;

        }
        return count;
    }
};