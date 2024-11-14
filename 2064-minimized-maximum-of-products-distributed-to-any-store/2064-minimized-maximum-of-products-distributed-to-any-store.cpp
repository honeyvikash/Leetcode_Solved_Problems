class Solution {
public:
    bool canDistribute(const vector<int>& quantities, int n, int x) {
        int stores_needed = 0;
        for (int quantity : quantities) {
            stores_needed += (quantity + x - 1) / x; 
 // Equivalent to ceil(quantity / x)
            if (stores_needed > n) return false;    
  // Too many stores needed
        }
        return true;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1, right = *max_element(quantities.begin(), quantities.end());
        int result = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canDistribute(quantities, n, mid)) {
                result = mid;       
// Update result to a smaller feasible value
                right = mid - 1;    
// Try for a smaller maximum
            } else {
                left = mid + 1;     
// Increase mid to try for a feasible solution
            }
        }

        return result;
    }
};