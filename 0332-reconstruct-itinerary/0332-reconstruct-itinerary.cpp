class Solution {
public:
    void dfs(string x,map<string,vector<string>>& adj,map<pair<string,string>,int>& vis,vector<string>& ans)
    {
        for(auto &i:adj[x])
        {
            if(vis[{x,i}]>0)
            {
                vis[{x,i}]--;
                dfs(i,adj,vis,ans);
            }
        }
        ans.push_back(x);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string,vector<string>> adj;
        map<pair<string,string>,int> vis;
        for(auto &i:tickets)
        {
            adj[i[0]].push_back(i[1]);
            vis[{i[0],i[1]}]++;
        }
        for(auto &i:adj)
        {
            sort(i.second.begin(),i.second.end());    
        }
        vector<string> ans;
        dfs("JFK",adj,vis,ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};