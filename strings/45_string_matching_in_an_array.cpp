#include<iostream>
#include<string>
#include<algorithm>

using namespace std;


//! Problem:
//! Given an array of strings, return all strings that are a substring of another string in the array.

//! Input:
//! words = {"mass", "as", "hero", "superhero"}
//! Output: {"as", "hero"}

//! Explanation:
//! "as" is a substring of "mass"
//! "hero" is a substring of "superhero"

//! Input:
//! words = {"leetcode", "et", "code"}
//! Output: {"et", "code"}

int main(){

  string words[] = {"mass", "as", "hero", "superhero"};
  int n = sizeof(words)/sizeof(words[0]);

  sort(words,words+n,[](const string &a , const string &b){
    return a.length() <  b.length(); //? The shorter strings will get placed first 
  });

  
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      if(words[j].find(words[i]) != string::npos){
        cout << words[i]  << " ";
        break; 
      }
    }
  }

}