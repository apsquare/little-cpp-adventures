#include<iostream>
#include<string>
#include<stack>

using namespace std;

//! Problem: Given a string s containing uppercase and lowercase English letters, repeatedly remove two adjacent characters when they are the same letter but opposite cases.
//! Input:  "leetcode"
//! Output: "leetcode"

int main(){

  string str;
  getline(cin,str);
  int n = str.length();

  stack<char> character_stack;

  for(int i=0;i<n;i++){
    if(character_stack.empty()){
      character_stack.push(str[i]);
    }else{

      if(toupper(str[i]) == toupper(character_stack.top())){
        if(isupper(str[i]) && isupper(character_stack.top()) || (islower(str[i]) && islower(character_stack.top()))){
          character_stack.push(str[i]);
        }else{
           character_stack.pop();
        }
      }else{
        character_stack.push(str[i]);
      }
      
    }
  }

  string result = "";
  while(!character_stack.empty()){
    result = character_stack.top() + result;
    character_stack.pop();
  }

  cout << result << endl;

}

