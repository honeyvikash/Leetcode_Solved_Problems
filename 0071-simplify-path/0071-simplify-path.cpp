class Solution {
public:
    string simplifyPath(string path) {
        vector<string> ans;
        string temp;
        for(auto val : path){
            if( '/'==val ){
                ans.push_back(temp);
                temp = "";
            }else
                temp.push_back(val);
        }
        if( ""!=temp )  ans.push_back(temp);
        string result;
        result.push_back('/');
        for(auto &val : ans){
            if( ".."==val ){
                if( 1!=result.size() && '/'==result.back() )    result.pop_back();
                while( '/'!=result.back() ) result.pop_back();
            }else if( "."==val || ""==val )    continue;
            else    result.append(val);
            if( result.back()!='/' )    result.push_back('/');
        }
        if( 1!=result.size() && '/'==result.back() )    result.pop_back();
        return result;
    }
};