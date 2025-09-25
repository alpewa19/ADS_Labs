#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next, *prev;
    
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class LinkedList{
    public:
    Node *tail, *front;
    
    LinkedList(){
        this->tail = NULL;
        this->front = NULL;
    }
    
    void push_back(int data){
        Node *new_node = new Node(data);
        if(tail == NULL){
            tail = new_node;
            front = new_node;
        }
        else{
            new_node->prev = tail;
            tail->next = new_node;
            tail = new_node;
        }
    }
    
    void push_front(int data){
        Node *new_node = new Node(data);
        if(front == NULL){
            tail = new_node;
            front = new_node;
        }
        else{
            new_node->next = front;
            front->prev = new_node;
            front = new_node;
        }
    }
    
    void pop_back(){
        if(tail != NULL){
            tail = tail->prev;
            if(tail != NULL){
                tail->next = NULL;
            }
            else{
                front = NULL;
            }
        }
    }
    
    void pop_front(){
        if(front != NULL){
            front = front->next;
            if(front != NULL){
                front->prev = NULL;
            }
            else{
                tail = NULL;
            }
        }
    }
    
    void del_node(Node *node){
        if(node == tail){
            pop_back();
        }
        else if(node == front){
            pop_front();
        }
        else{
            Node *a = node->prev;
            Node *b = node->next;
            a->next = b;
            b->prev = a;
        }
    }
    
    void print(){
        Node *node = front;
        while(node != NULL){
            cout << node->data << " ";
            node = node->next;
        }
        cout << endl;
    }
    
    void insert(int data, int position){
        if (position == 0) {
            push_front(data);
            return;
        }
        Node* current = front;
        for (int i = 0; i < position - 1 && current != NULL; ++i) {
            current = current->next;
        }
        if (current == tail) {
            push_back(data);
            return;
        }
        if (current == NULL) return;
        Node* new_node = new Node(data);
        Node* next_node = current->next;
        new_node->next = next_node;
        new_node->prev = current;
        current->next = new_node;
        if (next_node != NULL) {
            next_node->prev = new_node;
        }
    }
};

int main() {
    LinkedList list;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        list.push_back(a);
    }
    int number;
    cin >> number;
    int position;
    cin >> position;
    list.insert(number, position);
    list.print();
    
    return 0;
}