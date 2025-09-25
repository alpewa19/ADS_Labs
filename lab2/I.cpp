#include <iostream>
  
using namespace std;

struct Node{
	Node * prev;
	Node * next;
	string val;
	Node(string _val){
		prev = NULL;
		next = NULL;
		val = _val;
	}	
};

Node * head = NULL;
Node * tail = NULL;
int cnt;
void add_back(string s){
    Node *node=new Node(s);
    if (tail==NULL){
        tail=node;
        head=node;
    }
    else{
        node->prev=tail;
        tail->next=node;
        tail=node;
    }
}
void add_front(string s){
        Node *node = new Node(s);
        if (head == NULL) {
            tail = node;
            head = node;
        } else {
           head->prev = node;
            node->next =head;
            head = node;
        }
    }
bool empty(){
    if (head==NULL && tail==NULL) return true;
    else return false;
}
void erase_front(){
    if (head!=NULL){
		head=head->next;
		if (head!=NULL)
			head->prev=NULL;
		else
			tail=NULL;
    }
}
void erase_back(){
    if (tail!=NULL){
        tail=tail->prev;
        if (tail!=NULL)
            tail->prev=NULL;
        else
            head=NULL;
    }
}
string front(){
	return head->val;
}
string back(){
    return tail->val;
}
void clear(){
    Node* cur = head;
    while (cur){
        Node* nxt = cur->next;
        delete cur;
        cur = nxt;
    }
    head = tail = NULL;
}

  
int main()
{
	string s;
   	while(cin >> s){
   		if(s == "add_front"){
   			string t;
   			cin >> t;
   			add_front(t);
   			cout << "ok" << endl;
   		}
   		if(s == "add_back"){
   			string t;
   			cin >> t;
   			add_back(t);
   			cout << "ok" << endl;
   		}
   		if(s == "erase_front"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else
   			{
   				cout << front() << endl;
   				erase_front();
   			}
   		}
   		if(s == "erase_back"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << back() << endl;
   				erase_back();
   			}
   		}
   		if(s == "front"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << front() << endl;
   			}
   		}
   		if(s == "back"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << back() << endl;
   			}
   		}
   		if(s == "clear"){
   			clear();
   			cout << "ok" << endl;
   		}
   		if(s == "exit"){
   			cout << "goodbye" << endl;
   			break;
   		}
   	}
    return 0;
}