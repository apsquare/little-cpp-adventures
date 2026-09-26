#include<iostream>
#include<string>


using namespace std;

//! Problem: Given two strings a and b, find the minimum number of times you must repeat a so that b becomes a substring of the repeated string. If it's impossible, return -1. 

//! Input:
//! a = "abcd"
//! b = "cdabcdab"
//! Output: 3

int main(){

  string a , b;
  getline(cin,a);
  getline(cin,b);

  int a_length = a.length();
  int b_length = b.length();

  string repeated_a  = "";
  int repeat_count = 0;

  while(repeated_a.length() < b_length){
    repeated_a = repeated_a + a;
    repeat_count++;
  } 

  if(repeated_a.find(b) != string::npos){
    cout << repeat_count << endl;
    return 0;
  }else{
    repeated_a += a;
    repeat_count++;
  }

  if(repeated_a.find(b) != string::npos){
    cout << repeat_count << endl;
    return 0;
  }else{
    return -1;
  }

  




  







}