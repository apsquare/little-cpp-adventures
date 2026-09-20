#include<iostream>
#include<string>


//! Given two strings s1 and s2, determine whether s2 is a rotation of s1.
//! A string is considered a rotation if it can be obtained by shifting some characters from the beginning of the string to the end without changing their order.

//! s1 = "abcde" 
//! s2 = "cdeab"
//! s1 + s1 = abcdeabcde

using namespace std;

int main(){

  string s1, s2;
  getline(cin,s1);
  getline(cin,s2);
  int n1 = s1.length();   
  int n2 = s2.length();

  if(n1 != n2){
    cout << "False" << endl;
    return 0; 
  }

  string checkString = s1 + s1;
  if(checkString.find(s2) != string::npos ){
    cout << "True" << endl;
    return 0;
  }

  cout << "False" << endl;
  return 0;



}