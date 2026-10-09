#include<iostream>

using namespace std;

//! Implement the deleteAtBeginning function 
// ! 1->nullptr 2->3->4->5

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