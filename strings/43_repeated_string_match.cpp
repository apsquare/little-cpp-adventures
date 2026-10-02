#include<iostream>
#include<string>

using namespace std;

//! Problem:
//! Given two strings a and b, return the minimum number of times
//! you must repeat string a so that b becomes a substring of it.
//!
//! If it is impossible, return -1.

//! Input:
//! a = "abcd"
//! b = "cdabcdab"
//! Output: 3
//!
//! Explanation:
//! "abcd" repeated 3 times:
//! "abcdabcdabcd"
//!
//! "cdabcdab" is a substring of it.

//! Input:
//! a = "a"
//! b = "aa"
//! Output: 2

int main(){

  string a ,b;
  getline(cin,a);
  getline(cin,b);

  string repeated_a = a;
  int count = 1;

  while(repeated_a.length() < b.length()){
    repeated_a += a;
    count++;
  }


  if(repeated_a.find(b) != string::npos){
    cout << count << endl;
    return 0;
  }

  repeated_a += a;
  count++;

  if(repeated_a.find(b) != string::npos){
    cout << count << endl;
    return 0;
  }

  cout << -1 << endl;

}