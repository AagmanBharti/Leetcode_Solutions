class LRUCache {
public:
    
    class Node{
    public:
        int key,val;
        Node* prev;
        Node* next;
        
        Node(int k,int v){
            key=k;
            val=v;
            prev=next=NULL;
        }
    };
    
    int cap;
    unordered_map<int,Node*> mp;
    
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    void remove(Node* node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }
    
    void insert(Node* node){
        node->next=head->next;
        node->prev=head;
        head->next->prev=node;
        head->next=node;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        
        Node* node=mp[key];
        remove(node);
        insert(node);
        
        return node->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* node=mp[key];
            remove(node);
            mp.erase(key);
        }
        
        if(mp.size()==cap){
            Node* node=tail->prev;
            remove(node);
            mp.erase(node->key);
        }
        
        Node* node=new Node(key,value);
        insert(node);
        mp[key]=node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */