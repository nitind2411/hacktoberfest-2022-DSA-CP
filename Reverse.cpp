//CODE USING FIRST INTERESTING METHOD
#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node* next;

  //constructor
  Node(int data) {
    this->data=data;
    this->next=NULL;
    
  }
//destructor
    ~Node() {
        int value = this -> data;
        //memory free
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }
};
void insertatHead(Node* &head,int d){

  Node* temp=new Node(d);
  temp->next=head;
  head=temp;
  
}
void insertatTail(Node* &tail, int d) {
     // new node create
    Node* temp = new Node(d);
    tail -> next = temp;
    tail  = temp;
}
void print(Node* &head) {
  Node* temp=head;

  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
  }
  cout<<endl;
  
}
void reverse(Node* &head,Node* curr,Node* prev){
  if(curr==NULL){
    head=prev;
    return;
    }
  Node* forward=curr->next;
  reverse(head,forward,curr);
  curr->next=prev;
  }

Node* reverseLinkedList(Node* head){
  Node* curr=head;
  Node* prev=NULL;
  reverse(head,curr,prev);
  return head;

}


int main() {

  
  Node* node1=new Node(3);
  Node* head=node1;
  Node* tail=node1;
  insertatTail(tail,5);
  insertatTail(tail,7);
  insertatTail(tail,9);
  insertatTail(tail,11);
  print(head);
  reverseLinkedList(head);
  print(head);
}



//CODE USNG SECOND INTERESTING METHOD
#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node* next;

  //constructor
  Node(int data) {
    this->data=data;
    this->next=NULL;
    
  }
//destructor
    ~Node() {
        int value = this -> data;
        //memory free
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }
};
void insertatHead(Node* &head,int d){

  Node* temp=new Node(d);
  temp->next=head;
  head=temp;
  
}
void insertatTail(Node* &tail, int d) {
     // new node create
    Node* temp = new Node(d);
    tail -> next = temp;
    tail  = temp;
}
void print(Node* &head) {
  Node* temp=head;

  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
  }
  cout<<endl;
  
}
Node* reverse1(Node* head){
  if(head==NULL || head->next==NULL){
    return head;
  }
  Node* chotaHead=reverse1(head->next);
  head->next->next=head;
  head->next=NULL;

  return chotaHead;
}
Node* reverseLinkedList(Node* head){
  return reverse1(head);
}

int main() {

  
  Node* node1=new Node(3);
  Node* head=node1;
  Node* tail=node1;

  insertatTail(tail,5);
  insertatTail(tail,7);
  insertatTail(tail,9);
  insertatTail(tail,11);
  print(head);

  reverseLinkedList(head);

  cout<<"head "<<head->data<<endl;
  cout<<"tail "<<tail->data<<endl;

  
  }
