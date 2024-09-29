struct Node{
    public:
    int value;
    Node* prev;
    Node* next;
    Node(int value){
        this->value = value;
        this->prev = NULL;
        this->next = NULL;
    }
};

class MyCircularDeque {
public:
    int size = 0;
    int k;
    Node* head=NULL;
    Node* tail=NULL;
    
    MyCircularDeque(int p) {
        k = p;
    }
    
    bool insertFront(int value) {
        if(size == k) return false;
         size++;
        if(head == NULL and tail == NULL){
            head = new Node(value);
            tail = head;
           
        }
        else{
            Node* node = new Node(value);
            node->next = head;
            head->prev = node;
            head = node;
        }
        
        return true;
    }
    
    bool insertLast(int value) {
        if(size == k) return false;
        size++;
        if(head == NULL and tail == NULL){
            head = new Node(value);
            tail = head;
           
        }
        else{
            Node* node = new Node(value);
            node->prev = tail;
            tail->next=node;
            tail = node;
        }
        return true;
    }
    
    bool deleteFront() {
        if(size == 0) return false;
        size--;
        if(head == tail){
            head = NULL;
            tail = NULL;
            
        }
        else{
            head->next->prev = NULL;
            head = head->next;
        }
        
        return true;
        
    }
    
    bool deleteLast() {
        if(size == 0) return false;
        size--;
         if(head == tail){
            head = NULL;
            tail = NULL;
            
        }
        else{
            tail->prev->next = NULL;
            tail = tail->prev;
        }
        return true;
    }
    
    int getFront() {
        if(head == NULL) return -1;
        
        return head->value;
    }
    
    int getRear() {
        if(tail == NULL) return -1;
        return tail->value;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == k;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
