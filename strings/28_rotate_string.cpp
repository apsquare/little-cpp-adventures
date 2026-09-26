#include<iostream>
#include<string>

using namespace std;

//! Problem: Given two strings s and goal, return true if s can become goal after repeatedly moving the first character to the end.
//! Input:
//! s = "abcde"
//! goal = "cdeab"
//! Output: true 

int main(){

  string s ,goal ; //? If goal has to appear by moving first element of s to the end , it simply means that goal is another rotated string of s . So it must appearn in s+s (Solved earlier)

  getline(cin,s);
  getline(cin,goal);

  string repeated_s = s+s;

  if(repeated_s.find(goal) != string::npos){
    cout << "true" << endl;
  }else{
    cout << "false" << endl;
  }






}