class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& a) {
        sort(a.begin(),a.end());
        int difi=a[1]-a[0];
        for(int i=0;i<a.size()-1;i++)
        {
            if(a[i+1]-a[i]!=difi)
            {
                return 0;
            }
        }
        return 1;
    }
};