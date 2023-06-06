class Solution {
public:
    int findDuplicate(vector<int>& a) {
        //Linked List cycle detection method
        while(a[0]!=a[a[0]])swap(a[0],a[a[0]]);
        return a[0];
    }
};