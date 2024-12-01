class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int>s;
        int n=arr.size();
        
        for(int i=0;i<n;i++){
            int a=arr[i];
            int b=a*2;
            int c=a/2;
            if((s.find(b)!=s.end()) || (a%2==0 && s.find(c)!=s.end())){
                return true;
            }
            s.insert(a);
        }
        return false;

    }
};