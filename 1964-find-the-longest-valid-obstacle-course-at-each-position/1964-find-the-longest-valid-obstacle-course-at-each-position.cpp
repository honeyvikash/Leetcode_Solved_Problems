class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> ans;
        vector<int> helper;
        for(auto val : obstacles){
            auto it = upper_bound(helper.begin(),helper.end(),val)-helper.begin();
            if( it==helper.size() ){
                helper.push_back(val);
            }else{
                helper[it] = val;
            }
            ans.push_back(it+1);
        }
        return ans;
    }
};