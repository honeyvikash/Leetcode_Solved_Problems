class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        
        map<int,pair<int,int>> mp;
        map<int,int> pos,tmp;
        int n = positions.size();
        for(int i = 0 ; i < n ; ++i)
            mp[positions[i]] = {healths[i],directions[i]=='R'},
            pos[positions[i]] = i;

        stack<pair<int,pair<int,int>>> st;
        for(auto&[a,b]:mp){
            int strength = b.first;
            int direction = b.second;
            // cout<<direction<<" ";
            if(!st.empty()){

                if(!(st.top().second.first==1 && direction==0)){
                    st.push({strength,{direction,a}});
                }else{

                    while(!st.empty() && (st.top().second.first==1 && direction==0)  && strength>0){

                        if(st.top().first>strength){
                            strength = 0;
                            st.top().first--;
                            if(st.top().first==0)
                                st.pop();

                        }else if(st.top().first<strength){
                            st.pop();
                            strength--;
                        }else{
                            st.pop();
                            strength = 0;
                        }
                    }

                    if(strength>0)
                        st.push({strength,{direction,a}});
                }

            }else{
                st.push({strength,{direction,a}});
            }
        }
        
        while(!st.empty())
        {
            tmp[pos[st.top().second.second]] = st.top().first;
            st.pop();
        }

        vector<int> ans;
        for(auto&[a,b]:tmp)
            ans.push_back(b);
        return ans;
    }
};