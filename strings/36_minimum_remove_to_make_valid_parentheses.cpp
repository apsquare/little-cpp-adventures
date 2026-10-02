#include<iostream>
#include<string>
#include<stack>

using namespace std;

//! Problem: Given a string containing lowercase English letters and
//! parentheses '(' and ')', remove the minimum number of parentheses
//! so that the resulting string is valid.

//! A valid parentheses string:
//! - Every ')' must have a matching '(' before it.
//! - Every '(' must eventually have a matching ')'.
//! - Letters do not affect validity.

//! Input:  "lee(t(c)o)de)"
//! Output: "lee(t(c)o)de"

//! Input:  "a)b(c)d"
//! Output: "ab(c)d"

//! Input:  "))(("
//! Output: ""



int main(){

  string str ;
  getline(cin, str);
  stack<int> st;

  for(int i=0;i<str.length();i++){
    if(str[i] == '('){
      st.push(i);
    }else if(str[i] == ')'){
      if(!st.empty()){
        st.pop();
      }else{
        str[i] = '*'; //For the invalid ')' i'm directly putting '*'
      }
    }
  }

  // We are replacing the index of unmatched '(' with '*' as well
  while(!st.empty()){
      str[st.top()] = '*';
      st.pop();
  }

  string result = "";
  for(char ch : str){
    if(ch != '*'){
      result += ch;
    }
  }

  cout << result << endl;
  

}
