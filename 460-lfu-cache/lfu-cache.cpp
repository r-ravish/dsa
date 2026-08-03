class Node {
public:
    int key;
    int val;
    int freq;
    Node* next;
    Node* prev;
};

class LFUCache {
public:
    Node* head = new Node(-1, -1, -1);
    Node* tail = new Node(-1, -1, -1);

    void deleteNode(Node* temp){
        Node* prevNode = temp->prev;
        prevNode->next = temp->next;
        temp->next->prev = prevNode;
    }

    void insertAtHead(Node* temp){
        Node* nextHead = head->next;
        head->next = temp;
        temp->prev = head;

        temp->next = nextHead;
        nextHead->prev = temp;
    }

    void updateFreq(Node* node){
        node->freq++;
    }

    int cap;
    unordered_map<int, Node*> mpp;
    LFUCache(int capacity) {
        cap = capacity;
        mpp.clear();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(!mpp.contains(key)){
            return -1;
        }
        Node* temp  = mpp[key];
        updateFreq(temp);
        
        // in case of same node freq we need to return LRU therefore
        deleteNode(temp);
        insertAtHead(temp);

        return temp->val;
    }
    
    void put(int key, int value) {
        if(mpp.contains(key)){
            Node* temp = mpp[key];
            updateFreq(temp);
            temp->val=value;

            // in case of same node freq we need to return LRU therefore
            deleteNode(temp);
            insertAtHead(temp);
        }else{
            if(cap == mpp.size()){
                int mini = INT_MAX;
                for (auto it : mpp) {
                    mini = min(mini, it.second->freq);
                }
                Node* curr = tail->prev;
                while(curr != head){
                    if (curr->freq == mini) {
                        mpp.erase(curr->key);
                        deleteNode(curr);
                        break;
                    }
                    curr=curr->prev;
                }
            }
            Node* newNode = new Node(key, value, 1);
            mpp[key] = newNode;
            insertAtHead(newNode);
        }
    }   
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */