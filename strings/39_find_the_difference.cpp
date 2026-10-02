#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

//! Problem: You are given two strings s and t.
//! String t is created by randomly shuffling string s and then adding
//! exactly one extra character somewhere in t.
//! Find and return the extra character.

//! Input:
//! s = "abcd"
//! t = "abcde"
//! Output: 'e'


int main(){
  string s,t;
  getline(cin,s);
  getline(cin,t);

  unordered_map<char,int> freq;
  for(char ch : s){
    freq[ch]++;
  }

  for(char ch : t){
    if(freq.find(ch) == freq.end() || freq[ch] == 0){
      cout << ch << endl;
      break;
    }else{
      freq[ch]--;
    }
  }

}
