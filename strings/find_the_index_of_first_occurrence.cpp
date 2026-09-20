#include<iostream>
#include<string>

using namespace std;

//! 
//! Problem: Given two strings haystack and needle, return the index where needle first occurs in haystack. Return -1 if it doesn't exist.
//! haystack = "sadbutsad"
//! needle   = "sad"


int main(){

  string haystack , needle ;
  getline(cin , haystack);
  getline(cin ,needle);
  
  int haystack_length = haystack.length();
  int needle_length = needle.length();


  //? haystack_length - needle_length  --> We are keeping this buffer at the end so that we do not go index out of bound 

  for(int i=0;i<=haystack_length - needle_length ;i++){
    bool match = true; //? Let's start with this assumption that the needle is present 
    for(int j=0;j<needle_length;j++){
      if(haystack[i+j] != needle[j]){
        match = false;
        break;
      }
    }
    if(match){
      cout << i << endl;
      return 0;
    }
  }

  cout << -1 << endl;
  

}