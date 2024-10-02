class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sortedArray = arr;
        sort(sortedArray.begin(), sortedArray.end());

        int rank = 1;
        unordered_map<int, int> mp;

        for(int i = 0; i < sortedArray.size(); i++) {

            if(mp.find(sortedArray[i]) == mp.end()) {
                mp[sortedArray[i]] = rank++;
            }

        }

        for(int i = 0; i < arr.size(); i++) {
            arr[i] = mp[arr[i]];
        }

        return arr;
    }
};