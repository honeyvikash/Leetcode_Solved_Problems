class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
       map<int,int> mp1;
        for(auto it: arr1)mp1[it]++;
        vector<int> res;
        sort(arr1.begin(),arr1.end());
    
        for(auto it: arr2)
        {
            int ct = mp1[it];
            while(ct--)res.push_back(it);
            mp1[it]=0;
        }

        for(auto it: arr1)
        {
            if(mp1[it]!=0)res.push_back(it);
        }

        return res;
    }
};