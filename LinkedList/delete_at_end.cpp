#include<iostream>

using namespace std;

//! Implement the deleteAtEnd function 
// ! 1->2->3->4->nullptr

class Node{
  public :
    int data ;
    Node* next;
  
    Node(int value){
      data = value;
      next = nullptr; //* This avoids wild pointers
    }
};


int deleteAtBeginning(Node* &head){

  if(head == nullptr){
    return -1;
  }
  
  Node* temp = head;
  head = head->next;
  temp->next = nullptr;
  
  int value = temp->data;
  delete temp;
  return value;
}

//? 1->2->3->nullptr
//? 1->nullptr  

int deleteAtEnd(Node* &head){

  if(head == nullptr){
    return -1;
  }

  // * We had only one node i.e head
  if(head->next ==nullptr){
    int value =head->data;
    delete head;
    head = nullptr;
    return value;
  }

  Node* temp = head;


  while(temp->next->next != nullptr){
    temp = temp->next;
  }

  Node* end = temp->next;
  int value = end->data;
  temp->next = nullptr;
  delete end;
  return value;
  
}

int main(){
  int pos ,val ;

  int n ;
  cin >> n;

  Node* head = nullptr;
  Node* temp = nullptr;

  //! Creating the linked list of the specified length   with first n natural numbers as values 
  for(int i=0;i<n;i++){
    Node* newNode = new Node(i);
    if(head == nullptr){
      head = newNode;
      temp = newNode;
    }else{
      temp->next = newNode;
      temp = newNode;
    }
  }






}