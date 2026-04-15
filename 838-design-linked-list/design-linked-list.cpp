class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class MyLinkedList {
    Node* head;
    int size;

public:
    MyLinkedList() {
        head = NULL;
        size = 0;
    }
    
    int get(int index) {
        if(index < 0 || index >= size){
            return -1;
        }

        Node* temp = head;
        for(int i = 0; i < index; i++){
            temp = temp->next;
        }
        return temp->data;
    }
    
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        size++;
    }
    
    void addAtTail(int val) {
        Node* newNode = new Node(val);

        if(head == NULL){
            head = newNode;
            size++;
            return;
        }

        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index < 0 || index > size){
            return;
        }

        if(index == 0){
            addAtHead(val);
            return;
        }

        Node* newNode = new Node(val); 
        int curr = 0;
        Node* temp = head;
        while(curr != index-1){ 
            temp = temp->next; 
            curr++; 
            } 
        newNode->next = temp->next; 
        temp->next = newNode; 
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index >= size){
            return;
        }

        if(index == 0){
            Node* temp = head;
            head = head->next;
            delete temp;
            size--;
            return;
        }

        int curr = 0; 
        Node* prev = head; 
        
        while(curr != index-1){ 
            prev = prev->next; 
            curr++; 
            } 
            Node* temp = prev->next;
            prev->next = prev->next->next; 
            delete temp;
            size--;
    }
};