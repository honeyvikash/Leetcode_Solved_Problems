class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> mapping;
        for(int i=0 ; i<order.size() ; i++)
            mapping[order[i]] = i;
        int i=1;
        while( i<words.size() )
        {
            int ind = 0;
            bool isOk = false;
            while( ind<words[i-1].size() && ind<words[i].size() )
            {
                if( mapping[words[i-1][ind]]<mapping[words[i][ind]] )
                {
                    isOk = true;
                    break;
                }
                else if( mapping[words[i-1][ind]]>mapping[words[i][ind]] )
                {
                    return false;
                }
                ind += 1;
            }
            if( false==isOk )
            {
                if( ind!=words[i-1].size())
                    return false;
            }
            i += 1;
        }
        return true;
    }
};