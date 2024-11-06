class Solution {
public:

    unsigned int countSetBits(int n){
        return __builtin_popcount(n);
    }

    bool canSortArray(vector<int>& nums) {

        vector<int> arr;
        vector<pair<int, int>> rangeArr;

        for(int a : nums) {
            if(arr.size() == 0 || countSetBits(a) == countSetBits(arr.back())){
                arr.push_back(a);
            }
            else {
                rangeArr.push_back({*min_element(arr.begin(), arr.end()), *max_element(arr.begin(), arr.end())});
                arr.clear();
                arr.push_back(a);
            }
        }

        rangeArr.push_back({*min_element(arr.begin(), arr.end()), *max_element(arr.begin(), arr.end())});

        for(int i = 0; i<rangeArr.size()-1; i++){
            if(rangeArr[i].second > rangeArr[i+1].first) return false;
        }
        return true;
    }
};