#include<iostream>
#include<string>
#include<stack>

//! Problem: Given two strings s and t, return whether they are equal after processing all backspaces.
//! The character '#' represents a backspace, meaning it removes the previous character if one exists.

//! av -> av

using namespace std;

int main(){

  string s;
  getline(cin,s);
  int s_length = s.length();

  string t;
  getline(cin,t);
  int t_length = t.length();

  stack<char> stack_s;
  stack<char> stack_t;

  for(int i=0;i<s_length;i++){

    if(s[i]== '#'){

      //? We can only pop if the stack contains something
      if(!stack_s.empty()){
        stack_s.pop();
      }

    }else{
      //? For all characters other than '#' we can push them to the stack
      stack_s.push(s[i]);
    }
  }


  //? Convert stack_s back into a string
    string new_s = "";

    while(!stack_s.empty()){

        //? Stack gives characters in reverse order,
        //? so add each character to the beginning
        new_s = stack_s.top() + new_s;
        stack_s.pop();
    }


//? Same implementation with stack_t
    for(int i=0;i<t_length;i++){
      if(t[i] == '#'){
        if(!stack_t.empty()){
          stack_t.pop();
        }
      }else{
        stack_t.push(t[i]);
      }
    }

    string new_t = "";
    while(!stack_t.empty()){
        new_t = stack_t.top() + new_t;
        stack_t.pop();
    }


    if(new_s == new_t){
      cout << "strings are equal after processing" << endl;
    }else{
      cout << "strings are not equal processing" << endl;
    }

    return 0;



}