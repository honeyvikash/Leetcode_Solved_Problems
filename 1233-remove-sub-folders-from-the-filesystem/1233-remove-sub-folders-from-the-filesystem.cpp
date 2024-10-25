class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        // Specially for 3rd test case
        // x[prev.size()]=='/'
        vector<string>parent;
        sort(folder.begin(),folder.end());
        string prev="";
        for(auto &x:folder)
        {
            if(!prev.empty() && x.find(prev)==0 && x[prev.size()]=='/')continue;
             parent.push_back(x);
             prev=x;
        }
        return parent;
    }
};