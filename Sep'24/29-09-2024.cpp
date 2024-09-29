//using doubly linked list

struct Node{
    public:
    int freq;
    string key;
    Node* prev;
    Node* next;
    Node(string key){
        this->freq = 1;
        this->key = key;
        this->prev = NULL;
        this->next = NULL;
    }
};

class AllOne {
public:
    unordered_map<string,Node*>mp;
    Node* head;
    Node* tail;
    void moveToCorrectNextPosition(Node* node){
        
        Node* ptr = node->next;
        
        while(ptr!=tail and ptr->freq < node->freq){
            ptr = ptr->next;
        }
        
        if(ptr !=node->next){
            node->prev->next = node->next;
            node->next->prev = node->prev;
            node->next = ptr;
            ptr->prev->next = node;
            node->prev = ptr->prev;
            ptr->prev = node;  
        }
    }
    
    void moveToCorrectPrevPosition(Node* node){
        Node* ptr = node->prev;
        
        while(ptr != head and ptr->freq > node->freq){
            ptr = ptr->prev;
        }
        
        if(ptr != node->prev){
            node->prev->next = node->next;
            node->next->prev = node->prev;
            node->next = ptr;
            ptr->prev->next = node;
            node->prev = ptr->prev;
            ptr->prev = node;
            
        }
    }
    
    AllOne() {
        head = new Node("");
        head->next = new Node("");
        tail = head->next;
        tail->prev = head;
    }
    
    void inc(string key) {
        Node* node;
        if(mp.find(key) == mp.end()){
             node= new Node(key);
             node->next = head->next;
             head->next->prev = node;
             head->next = node;
             node->prev = head;
            
            mp[key] = node;
        }
        else{
            node = mp[key];
            node->freq++;
            moveToCorrectNextPosition(node);
        }
        
        
    }
    
    void dec(string key) {
        // cout<<key<<"\n";
        Node* node = mp[key];
        // cout<<node->freq<<"\n";
        node->freq--;
        
        if(node->freq == 0){
            node->prev->next = node->next;
            node->next->prev = node->prev;
            delete node;
            mp.erase(key);
        }
        
        else moveToCorrectPrevPosition(node);
        
        
    }
    
    string getMaxKey() {
        if(tail->prev == head) return "";
        
        return tail->prev->key;
        
    }
    
    string getMinKey() {
      if(head->next == tail) return "";
        return head->next->key;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
