#include<iostream>
#include<string>
#include <vector>
#include <unordered_map>


using namespace std;

//* Problem: You are given a list of words and a string pattern.
//* Return all words that match the same character pattern as pattern.
//* Two strings match if there is a one-to-one mapping between their characters.

int main(){

  vector<string> words = {
    "abc",
    "deq",
    "mee",
    "aqq",
    "dkd",
    "ccc"
  };

  string pattern = "abb";
  
  for(auto word : words){
    unordered_map<char, char> patternToWord;
    unordered_map<char, char> wordToPattern;

    bool match = true;

    for(int i=0;i<pattern.length();i++){
      char p = pattern[i];
      char w = word[i];

      if(patternToWord.find(p) != patternToWord.end()){ //? The character has appeared before 
        if(patternToWord[p] != w){
          match = false ;
          break;
        }

      }else{
        patternToWord[p] = w;
      }

      if(wordToPattern.find(w) != wordToPattern.end()){
        if(wordToPattern[w] != p){
          match = false;
          break;
        }

      }else{
          wordToPattern[w] = p;
      }

    }

    if(match){
      cout << word <<endl;
    }


  }



  




}