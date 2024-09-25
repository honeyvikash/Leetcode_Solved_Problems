class Node{
    private:
    unordered_map<char,Node*> arr;
    int cnt;
    public:
    Node(){   
     cnt=0;
    //  arr=vector<Node*>(26,NULL);
    }
    Node* getVal(char c)
    {
        if(arr.find(c)!=arr.end())
        return arr[c];
        return NULL;
    }
    int getCount()
    {
       return cnt;
    }
    void setNode(char c,Node* p)
    {
        arr[c]=p;
    }
    void increaseCnt()
    {
        cnt++;
    }
};
class Trie {
    private: 
    Node* root=NULL;
    public:
    Trie(){
      root = new Node();
    }
    void insert(string s)
    { 
        Node* curr=root;
        for(auto p: s)
        {
        if(curr->getVal(p)==NULL)
        {
            auto newNode= new Node();
            curr->setNode(p,newNode);
        }
        curr=curr->getVal(p); 
        curr->increaseCnt();
        }
    }

    int  getprefixCnt(string s)
    {
        Node* curr=root;
        int cnt=0;
        for(auto c: s)
        {
            curr = curr->getVal(c);
            cnt+=curr->getCount();
        }
        return cnt;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        
        int n=words.size();
        Trie t;
        vector<int> result(n);
        
        for(auto word: words)
        {
           t.insert(word);    
        }
        for(int i=0;i<n;i++)
        {
            result[i]=t.getprefixCnt(words[i]);
        }
        return result;
        
    }
};