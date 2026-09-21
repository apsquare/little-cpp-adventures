#include<iostream>
#include<stack>


//! Problem: Given a string s, repeatedly remove two adjacent equal characters. Continue until no more such pairs exist.
//! Input:  "abbaca" --> "ca"
//! Output: "ca"

using namespace std;

int main(){
  string str;
  getline(cin,str);
  int n = str.length();

  stack<char> character_stack;

  for(int i=0;i<n;i++){
    if(character_stack.empty()){
      character_stack.push(str[i]);
    }else{
      if(character_stack.top() == str[i]){
        character_stack.pop();
      }else{
        character_stack.push(str[i]);
      }
    }
  }

  string result = "";
  while(!character_stack.empty()){
    result =  character_stack.top() + result;
    character_stack.pop();
  }
  cout << result << endl;



}

