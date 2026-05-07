class LRUCache {
public:
    class Node {
        public:
            Node* next;
            Node* prev;
            int key, val;
            Node(int k, int v){
                key = k;
                val = v;
                next = prev = NULL;
            }
    };
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    int limit;
    unordered_map<int, Node*> m;

    void addNode(Node* newNode){
        Node* temp = head->next;
        head->next = newNode;
        newNode->prev = head;
        newNode->next = temp;
        temp->prev = newNode;
    }
    void delNode(Node* oldNode){
        Node* oldnext = oldNode->next;
        Node* oldprev = oldNode->prev;
        
        oldprev->next = oldnext;
        oldnext->prev = oldprev;
    }
    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(m.find(key) == m.end()){
            return -1;
        }
        Node* targetNode = m[key];
        delNode(targetNode);
        addNode(targetNode);
        return targetNode->val;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()){
            Node* oldNode = m[key];
            delNode(oldNode);
            m.erase(key);
            delete oldNode;
        }
        //capacity check
        if(m.size() == limit){
            m.erase(tail->prev->key);
            Node* lastNode = tail->prev;
            delNode(lastNode);
            delete lastNode;
        }
        Node* newNode = new Node(key, value);
        addNode(newNode);
        m[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */