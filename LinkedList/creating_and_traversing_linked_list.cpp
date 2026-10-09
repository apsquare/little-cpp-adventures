#include<iostream>

using namespace std;

//! Creating a linked list  

//* A linked list is a linear data structure where each node stores data and a pointer to the next node.
//* 1 -> 2 -> 3 -> 4 -> nullptr 

class Node{
  public :
    int data ;
    Node* next;
  
    Node(int value){
      data = value;
      next = nullptr; //* This avoids wild pointers
    }
};

int main(){

  int n; //* The number of nodes we need in the linked list
  cin >> n;

  Node* head = nullptr; //* This points to the beginng of the linked list
  Node* temp = nullptr; //* This temp pointer is used to move through the linked list 

  for(int i=0;i<n;i++){
    int value ;
    cin >> value;

    Node* newNode = new Node(value);

    if(head == nullptr){
      head = newNode;
      temp = newNode;
    }else{
      temp->next = newNode;
      temp = newNode;
    }
  }

  //* Traversal of the linked list created 
  temp = head;

  while(temp!=nullptr){
    cout << temp->data << " " ;
    temp = temp->next;
  }
  return 0;

}