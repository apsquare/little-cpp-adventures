#include<iostream>
#include<string>


using namespace std;  

//! Question: Given two strings s1 and s2, determine whether they are anagrams. Two strings are anagrams if they contain exactly the same characters with the same frequencies, possibly in a different order. 
//! Example: "listen" and "silent" → true


int main(){


  string s1,s2;
  getline(cin,s1);
  getline(cin,s2);

  int length1= s1.length();
  int length2= s2.length();


  //? TO be anagrams , the lengths of both the strings must be equal. 
  if(length1 != length2){
    cout << "Not anagrams" << endl;
    return 0;
  }

  int freq[256] = {0};

  for(int i=0;i<length1;i++){
    freq[s1[i]]++;
  }

  for(int i=0;i<length2;i++){
    freq[s2[i]]--;
  }

  for(int i=0;i<256;i++){
    if(freq[i] != 0){
      cout << "Not anagrams" << endl;
      return 0;
    }
  }

  cout << "Anagrams" << endl;

} 