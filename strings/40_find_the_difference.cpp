#include<iostream>
#include<string>

using namespace std;

//! Problem: You are given two strings s and t.
//! String t is created by randomly shuffling string s and then adding
//! exactly one extra character somewhere in t.
//! Find and return the extra character.

//! Input:
//! s = "abcd" --> 0^a^b^c^d
//! t = "abcde" --> 0^a^b^c^d^a^b^c^d^e
//! Output: 'e'

//! a ^ a ^ b ^ b ^ c ^ c ^ d^d ^ e --> e 
//! (a ^ a) ^ (b ^ b) ^ (c ^ c) ^ d --> so at the end 'd' will be left as answer because a^a = 0, b^b = 0, c^c = 0 and 0^d = d  


int main(){

  string s , t;
  getline(cin,s);
  getline(cin,t);

  char answer = 0;
  for(char ch : s){
    answer ^= ch;
  }

  for(char ch : t){
    answer ^= ch;
  }

  cout << answer << endl;

}