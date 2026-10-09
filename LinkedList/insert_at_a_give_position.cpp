#include<iostream>

using namespace std;

//! Write a function to insert a node at the given index 
//* head -> nullptr

class Node{
  public :
    int data ;
    Node* next;
  
    Node(int value){
      data = value;
      next = nullptr; //* This avoids wild pointers
    }
};

//? Don't make a copy of the pointer. Give me a reference to the original pointer itself. 
//? Function to insert a node at the beginning of the linked list
void insertAtBeginning(Node* &head,int value ){
  Node* newNode = new Node(value);
  newNode->next = head;
  head = newNode;
}


//? Function to insert a node at the end of the linked list
void insertAtEnd(Node* &head, int value){
  Node* newNode = new Node(value);

  //* This means that the linked list is empty and we are adding the first element  
  if(head == nullptr){
    head = newNode;
    return ;
  }

  Node* temp = head;
  //* This will make sure that we stop at the last node  
  //* 1->2->3->4->5->nullptr 
  while(temp->next != nullptr){
    temp = temp->next;
  }

  temp->next = newNode;

}

int main(){

  int n; //* The number of nodes we need in the linked list
  cin >> n;

  Node* head = nullptr; //* This points to the beginng of the linked list
  Node* temp = nullptr; //* This temp pointer is used to move through the linked list 

  //? Code to create a linked list
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

  int insertion_value ;
  cin >> insertion_value;
  insertAtEnd(head,insertion_value);

}