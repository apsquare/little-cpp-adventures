#include<iostream>
#include<string>


using namespace std;

//! Problem: Given a string s containing only 'a', 'b', and 'c',

//! repeatedly perform the following operation:
//! Choose a non-empty prefix where every character is the same.
//! Choose a non-empty suffix where every character is the same.
//! The prefix and suffix must contain the SAME character.
//! They must not overlap.
//! Remove both.
//! Return the minimum possible length of the string.

//! Input:  "ca"
//! Output: 2

//! Input:  "cabaabac"
//! Output: 0

//! Input:  "cca"
//! Output: 3

//! "" 


int main(){

  string str;
  getline(cin,str);
  int n = str.length();


  int left = 0 , right = n-1;

  while(left < right ){
    if(str[left] == str[right]){
      char current_character = str[left];
      while(left <= right && str[left] == current_character){
        left++;
      }
      while(left <= right && str[right] == current_character){
        right--;
      }
    }else{
      break;
    }
  }

  cout << right - left + 1 << endl;

}