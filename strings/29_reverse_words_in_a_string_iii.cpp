#include<iostream>
#include<sstream>
#include<vector>
#include <algorithm>
#include <string>

using namespace std;

//! Problem: Given a string s, reverse the characters inside each word, while keeping the words in their original positions.

//! Input:
//! "Let's take LeetCode contest"

//! Output:
//! "s'teL ekat edoCteeL tsetnoc"

//? A stringstream will read the string till the next whitespace --> We can break the string into workds using it 

int main(){
  string s;
  getline(cin,s);

  stringstream ss(s); //? Created a stringstream for s
  vector<string> words;

  string word ;
  while(ss >> word){
    words.push_back(word);
  }

  string reversed_string = "";
  for(auto &w : words ){
    reverse(w.begin(),w.end());
    if(!reversed_string.empty()){
      reversed_string = reversed_string + " " ;
    }
    reversed_string += w;
  }

  cout << reversed_string << endl;





}