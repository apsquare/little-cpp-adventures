/*
 * VALID PALINDROME (two pointers)
 *
 * Problem    : Given a string, decide whether it reads the same both ways
 *              once case is ignored and every non-alphanumeric character
 *              (spaces, commas, punctuation) is skipped.
 * Input      : one line of text
 * Output     : Palindrome or Not Palindrome
 * Idea       : Walk a pointer in from each end, skipping anything that is
 *              not alphanumeric, and compare the lowercased characters.
 * Complexity : Time O(n)   Space O(1)
 */

#include<iostream>
#include<cctype>  // ? This lib is used to check individual characters in c++
//! Given a string s, determine whether it is a palindrome after:
//!ignoring uppercase/lowercase differences;
//!ignoring all non-alphanumeric characters (spaces, commas, punctuation, etc.).


using namespace std;

int main(){

  //? Taking  string input
  string s;
  getline(cin,s); 
  
  int left = 0;
  int right = s.length()-1;

  while(left <= right){
    if(!isalnum(s[left])){
      left ++;
    }else if(!isalnum(s[right])){
      right--;
    }else{
      //? If the elements are not equal then the string is not a palindrome 
      if(tolower(s[left]) != tolower(s[right])){
        cout << "Not Palindrome" << endl;
        return 0 ;
      }

      //? If they are equal move to the next index 
      left++;
      right--;
    }

  }

    cout << "Palindrome" <<endl;

}