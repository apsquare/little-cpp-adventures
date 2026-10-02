#include<iostream>
#include<string>
#include<algorithm>
#include<sstream>

using namespace std;

//! Problem:
//! Given a sentence and a searchWord, return the 1-based index of the first word in the sentence where searchWord is a prefix.
//! If searchWord is not a prefix of any word, return -1.

//! Input:
//! sentence = "i love eating burger"
//! searchWord = "burg"
//! Output: 4
//! "burg" is a prefix of "burger".

//? We need to return the word number in the sentence starting from 1 

int main(){

  string sentence ;
  getline(cin,sentence);

  string prefix;
  getline(cin,prefix);
  int n = prefix.length();

  stringstream ss(sentence);
  string word;
  bool found  = false;
  int word_count = 0;
  while(ss >> word){
    word_count++;
    string subString  = word.substr(0,n);
    if(subString == prefix){
      found = true;
      break;
    }
  }

  if(found){
    cout << word_count << endl;
  }else{
    cout << -1 << endl;
  }




}
