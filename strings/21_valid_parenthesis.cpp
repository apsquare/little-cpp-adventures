#include<iostream>
#include<string>
#include<stack>

//! Problem: Given a string s containing only the characters '(', ')', '{', '}', '[', and ']', determine whether the string contains valid parentheses.
//! A string is valid if:
//! Every opening bracket is closed by the same type of bracket.
//! Every opening bracket is closed in the correct order.
//! Every closing bracket has a corresponding opening bracket.

//! ()[]{}      → Valid
//! ([{}])      → Valid
//! (]          → Invalid   
//! ([)]        → Invalid   

using namespace std;

int main(){

  string str ;
  getline(cin,str);
  int n = str.length();


  stack<char> para;
  for(int i=0;i<n;i++){
    if(str[i] == ')' || str[i] == '}' || str[i] == ']'){
      if(para.empty()){
        cout << "Invalid" << endl;
        return 0 ;
      }else if(para.top() == '(' && str[i] == ')'){
        para.pop();
      }else if(para.top() == '{' && str[i] == '}'){
        para.pop();
      }else if(para.top() == '[' && str[i] == ']'){
        para.pop();
      }else{
        cout << "Invalid" << endl;
        return 0;
      }
    }else{
      para.push(str[i]);
    }
  }

  if(para.empty()){
    cout << "Valid" << endl;
  }else{
    cout << "Invalid" << endl;
  }






}




