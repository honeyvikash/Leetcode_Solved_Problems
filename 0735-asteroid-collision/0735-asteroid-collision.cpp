class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        int n = a.size();
        vector<int>s;
        for(int i =0;i<n;i++)
        {
            if(s.size()==0 || a[i]>0)
            {
                s.push_back(a[i]);
            }
            else
            {
                while(!s.empty() and s.back()>0 and s.back()<abs(a[i]))s.pop_back();
                
                if(!s.empty() and s.back()+a[i]==0)
                {
                    s.pop_back();
                }
                else if(s.empty() || s.back()<0) s.push_back(a[i]);
            }
        }
        return s;
    }
};