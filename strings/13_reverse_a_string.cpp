#include<iostream>
#include<string>


using namespace std;


//! Question: Given a string s, reverse the string without using the built-in reverse() function.
//! Example: "hello" → "olleh"
//! Target: O(n) time and O(1) extra space.

int main(){

  string s;
  getline(cin,s);
  int n = s.length();

  for(int i=0;i<n/2;i++){
    char temp = s[i];
    s[i] = s[n-i-1];
    s[n-i-1] = temp;
  }

  cout << s << endl;

}