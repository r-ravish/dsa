class Node {
public:
    int key;
    int val;
    Node* next;
    Node* prev;

    Node(int k, int v) {
        key = k;
        val = v;
        next = nullptr;
        prev = nullptr;
    }
};



class LRUCache {
public:
    unordered_map<int,Node*> mpp;
    int cap;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    void deleteNode(Node* node){
        Node* prevNode;
        prevNode = node->prev;
        prevNode->next = node->next;
        node->next->prev = prevNode;
    }
    void insertAfterHead(Node* node){
        Node* temp;
        temp = head->next;
        head->next = node;
        node->prev = head;
        node->next = temp;
        temp->prev = node;
    }

    LRUCache(int capacity) {
        cap = capacity;
        mpp.clear();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(!mpp.contains(key)) return -1;
        Node* node = mpp[key];
        deleteNode(node);
        insertAfterHead(node);

        return node->val;
    }
    
    void put(int key, int value) {
        if(mpp.contains(key)){
            Node* node = mpp[key];
            node->val = value;
            deleteNode(node);
            insertAfterHead(node);
        }else{
            if(mpp.size() == cap){
                Node* node = tail->prev;
                mpp.erase(node->key);
                deleteNode(node);
            }
            Node* node = new Node(key, value);
            mpp[key] = node;
            insertAfterHead(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */