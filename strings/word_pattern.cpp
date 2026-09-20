#include<iostream>
#include<vector>
#include<sstream>
#include<unordered_map>

//! Given a pattern and a string s, check whether the words in s follow the pattern with a one-to-one mapping.

//! pattern = "abba"
//! s = "dog cat cat dog"
//! Output: true 
//! a → dog
//! b → cat

using namespace std;


int main(){

  string s;
  getline(cin,s);

  string pattern ;
  getline(cin,pattern);

  string word;
  vector<string> words;
  stringstream ss(s);

  while(ss >> word){
    words.push_back(word);
  }

  if(words.size() != pattern.size()){
    cout << "String does not follow the pattern";
    return 0;
  }

  unordered_map<char, string> patternToWord; //? This will check the pattern to word mapping 
  unordered_map<string, char> wordToPattern; //? This will check the word to pattern mapping
  int n = words.size();

  for(int i=0;i<n;i++){

    char currentPattern = pattern[i];
    string currentWord = words[i];

    if(patternToWord.find(currentPattern) != patternToWord.end()){
      if(patternToWord[currentPattern] != currentWord){
        cout << "String does not follow the pattern";
        return 0;
      }
    }

    if(wordToPattern.find(currentWord) != wordToPattern.end()){
      if(wordToPattern[currentWord] != currentPattern ){
        cout << "String does not follow the pattern";
        return 0;
      }
    }

    wordToPattern[currentWord] = currentPattern;
    patternToWord[currentPattern] = currentWord;

  }

  cout << "String follows the pattern" << endl;
  return 0;

}