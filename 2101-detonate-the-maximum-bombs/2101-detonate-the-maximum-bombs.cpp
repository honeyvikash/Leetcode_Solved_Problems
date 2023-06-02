class Solution {
public:
    bool isPos(vector<int> &p1,vector<int> &p2)
    {
        double distance = std::sqrt(std::pow((p2[0] - p1[0]), 2) + std::pow((p2[1] - p1[1]), 2));

        if (distance < p2[2]) 
        {
            return true;
        }
        else if (distance == p2[2]) 
        {
            return true;
        }

        return false;
    }
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        int len = bombs.size();
        int ans = 0;
        for(int i=0 ; i<bombs.size() ; i++){
            queue<int> q;
            vector<int> vis(len,false);
            q.push(i);
            vis[i] = true;
            int cnt = 1;
            while( !q.empty() )
            {
                for(int j=0 ; j<bombs.size() ; j++)
                {
                    if( isPos(bombs[j],bombs[q.front()]) && false==vis[j] )
                    {
                        vis[j] = true;
                        q.push(j);
                        cnt += 1;
                    }
                }
                q.pop();
            }
            ans = max(ans,cnt);
        }
        return ans;
    }
};