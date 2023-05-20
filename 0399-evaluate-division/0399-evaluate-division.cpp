class Solution {
    unordered_map<string,vector<pair<string,double>>> ump;
    unordered_map<string,bool> visited;
public:
    double helper(string &root,string &target){
        // cout<<root<<" ";
        // if( root==target )  return 1;
        visited[root] = true;
        double ans = 1;
        for(auto &val : ump[root]){
            if( val.first==target )    return val.second;
            if( false==visited[val.first] ){
                double temp = helper(val.first,target);
                if( 0!=temp ){
                    ans *= temp*val.second;
                    return ans;
                }
            }
        }
        return 0;
    }
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& values, vector<vector<string>>& queries) {
        for(int i=0 ; i<eq.size() ; i++){
            ump[eq[i][0]].push_back({eq[i][1],values[i]});
            ump[eq[i][1]].push_back({eq[i][0],1.0/values[i]});
        }
        vector<double> ans;
        for(auto val : queries){
            
            visited.clear();
            double temp = helper(val[0],val[1]);

            ans.push_back(0==temp?-1:temp);
            // cout<<"\n";
        }
        return ans;
    }
};