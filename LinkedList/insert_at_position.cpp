#include<iostream>

using namespace std;

//! Given a singly linked list, insert a new node with value 25 at position 3
//! Original list:
//! 10 → 20 -> 25 -> 30 → 40 → NULL
//! Position:
//!  1    2    3    4
//! Insert 25 at position 3
//! Result:
//! 10 → 20 → 25 → 30 → 40 → NULL

class Node{
  public :
    int data ;
    Node* next;
  
    Node(int value){
      data = value;
      next = nullptr; //* This avoids wild pointers
    }
};


void insertAtBeginning(Node* &head,int value ){
  Node* newNode = new Node(value);
  newNode->next = head;
  head = newNode;
}


int main(){
  int pos ,val ;

  Node* head = nullptr;
  Node* first = nullptr;
  Node* second = nullptr;

  int n ;
  cin >> n;

  for(int i=0;i<n;i++){
    Node* newNode = new Node(i);
    if(head == nullptr){
      head = newNode;
      first = newNode;
    }else{
      first->next = newNode;
      first = newNode;
    }
  }

  cin >> pos;
  cin >> val;


   if(pos < 1 || pos > n+1){
    return 1;
   }

  if(pos == n+1){
    first->next = new Node(val);
  }else if(pos == 1){
    insertAtBeginning(head,val);
  }else{
    first = head->next;
    second = head;
    int i=2;
    while(i+1<pos){
      second = first;
      first = first->next;
      i++;
    }
    Node* newNode = new Node(val);
    newNode->next = first;
    second->next = newNode;
    
  }

  first = head;
  while(first != nullptr){
    cout << first->data << " ";
    first = first->next;
  }
  cout << endl;

}