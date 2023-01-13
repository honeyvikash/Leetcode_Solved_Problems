class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        int sum = 0;
        while (left < right) {
            sum = numbers[left] + numbers[right];

            if (sum == target) 
            {
                return {left + 1, right + 1};
            } 
            else if (sum < target) 
            {
                auto it = lower_bound(numbers.begin(), numbers.end(), target - numbers[right]);
                left = it - numbers.begin();
            } 
            else 
            {
                auto it = upper_bound(numbers.begin(), numbers.end(), target - numbers[left]);
                right = it - numbers.begin();
                --right; // its gives just greater than required value so -- is req here.
            }
        }
        return {0, 0};
    }
};