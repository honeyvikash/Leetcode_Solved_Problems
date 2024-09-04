class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        map<pair<int,int>,int> m;
        for(int i=0;i<obstacles.size();i++){
            m[{obstacles[i][0],obstacles[i][1]}]++;
        }
        int x=0;
        int y=0;
        int maxi=0;
        vector<pair<int,int>> v={{0,1},{1,0},{0,-1},{-1,0}};
        int j=0;
        for(int i=0;i<commands.size();i++){
            if(commands[i]==-1){
                j++;
            }else if(commands[i]==-2){
                j--;
                if(j<0)
                j=3;
            }else{
                int k=commands[i];
                int l=0;
                j=j%4;
                while(l<k){
                if(m.find({x+v[j].first,y+v[j].second})!=m.end())
                break;
                x+=(v[j].first);
                y+=(v[j].second);
                maxi=max(maxi,(int)(pow(x,2)+pow(y,2)));
                l++;
                }
            }
        }
        return maxi;
    }
};