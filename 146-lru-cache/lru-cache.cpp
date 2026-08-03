class Node {
public:
    int key;
    int val;
    Node* next;
    Node* prev;
};

class LRUCache {
public:
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    void deleteNode(Node* temp){
        Node* prevNode = temp->prev;
        prevNode->next = temp->next;
        temp->next->prev = prevNode;
    }
    void insertAtHead(Node* node){
        Node* nextNode = head->next;
        head->next = node; 
        node->prev = head;
        node->next = nextNode;
        nextNode->prev = node;
    }

    
    unordered_map<int, Node*> mpp;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
        mpp.clear();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(!mpp.contains(key)){
            return -1;
        }
        Node* node = mpp[key];
        deleteNode(node);
        insertAtHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mpp.contains(key)){
            Node* temp = mpp[key];
            temp->val = value;
            deleteNode(temp);
            insertAtHead(temp);
        }else{
            if(cap == mpp.size()){
                Node* t = tail->prev;
                mpp.erase(t->key);
                deleteNode(t);
            }
            Node* newNode = new Node(key, value);
            mpp[key] = newNode;
            insertAtHead(newNode);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */