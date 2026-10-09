#include<iostream>


using namespace std;

//! Write a function to insert a node at the beginning of a linked list 
//* 0->1->2->3->4->5->nullptr 

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
void insertAtBeginning(Node* &head,int value ){
  Node* newNode = new Node(value);
  newNode->next = head;
  head = newNode;
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
  insertAtBeginning(head,insertion_value);

}