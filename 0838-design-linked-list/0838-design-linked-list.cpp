class Node {
public:
    int val_;
    Node* next;

    Node (int val) {
        val_ = val;
        next = nullptr;
    }
};

class MyLinkedList {
public:
    Node* head;
    // Node* tail;
    int size;

    MyLinkedList() {
        head = nullptr;
        size = 0;
    }
    
    int get(int index) {
        if (index < 0 || index >= size) return -1;
        else {
            Node* cur = head;
            for (int i = 0; i < index; i++) {
                cur = cur->next;
            }
            return cur->val_;
        }
        return -1;
    }
    
    void addAtHead(int val) {
        Node* temp = new Node(val);
        if (size == 0) head = temp;
        else {
            temp ->next = head;
            head = temp;
        }
        size++;
    }
    
    void addAtTail(int val) {
        Node* temp = new Node(val);

        if (size == 0) head = temp;
        else {
            Node* cur = head;
            while (cur->next != nullptr) {
                cur = cur -> next;
            }
            cur ->next = temp;
        }
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index<0 || index>size) return;
        else if (index == 0) {
            addAtHead(val);
        } 
        else if (index == size) addAtTail(val);
        else {
            Node* cur = head;
            for (int i = 0; i < index - 1; i++) {
                cur = cur->next;
            }
            Node* temp = new Node(val);
            temp->next = cur->next;
            cur->next = temp;
            size++; 
        }
    }
    
    void deleteAtIndex(int index) {
        if(index<0 || index>=size) return;
        else if (index == 0) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            size--;
        }
        else {
            Node* cur = head;
            for (int i = 0; i < index - 1; i++) {
                cur = cur->next;
            }
            Node* toDelete = cur->next;
            cur->next = toDelete->next;
            delete toDelete;
            size--;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */