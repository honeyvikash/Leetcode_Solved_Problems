class LRUCache {
public:
    class Node
    {
        public:
            Node* next = NULL;
            Node* prev = NULL;
            int val;
            int key;
        public:
            Node(int key,int val)
            {
                this->val = val;
                this->key = key;
            }
    };
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    unordered_map<int,Node*> m;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(m.find(key)==m.end())
        return -1;
        int val = m[key]->val;
        m[key]->prev->next = m[key]->next;
        m[key]->next->prev = m[key]->prev;
        delete(m[key]);
        Node* node = new Node(key,val);
        node->next = head->next;
        head->next = node;
        node->next->prev = node;
        node->prev = head;
        m[key] = node;
        return val;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end())
        {
            m[key]->val = value;
            m[key]->prev->next = m[key]->next;
            m[key]->next->prev = m[key]->prev;
            delete(m[key]);
        }
        else if(m.size()==cap)
        {
            Node* node1 = tail->prev;
            m.erase(node1->key);
            tail->prev = node1->prev;
            if(tail->prev!=NULL)
            tail->prev->next = tail;
            delete(node1);
        }
        Node* node = new Node(key,value);
        node->next = head->next;
        head->next = node;
        node->next->prev = node;
        node->prev = head;
        m[key] = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */