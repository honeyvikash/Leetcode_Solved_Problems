class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m=box.size(),n=box[0].size();

        vector<vector<char>> ans(m,vector <char>(n,'.'));

        // rotating box
        vector<vector<char>> box2(n,vector <char>(m,'.'));

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                box2[j][m-i-1]=box[i][j];
            }
        }
        vector <char> temp(m,'*');
        box2.push_back(temp);

        // ##freefall

        for(int j=0;j<m;j++)
        {
            int stones=0,last=0;
            for(int i=0;i<=n;i++)
            {
                if(box2[i][j]=='*')
                {
                    for(int k=last;k<i;k++)
                    {
                        box2[k][j]='.';
                    }

                    for(int k=i-1,c=0;c<stones;c++,k--)
                    {
                        box2[k][j]='#';
                    }

                    stones=0;
                    last=i+1;
                }
                else if(box2[i][j]=='#')
                stones++;
            }
        }
        box2.pop_back();
        return box2;
        
    }
};