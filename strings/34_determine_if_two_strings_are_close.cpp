#include<iostream>
#include<string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

//* Pattern: Frequency + Character Set
//! You are given two strings word1 and word2.
//! You can perform these operations any number of times:
//! 1. Swap any two existing characters.
//! 2. Transform every occurrence of one existing character into another existing character, and vice versa.
//! Determine whether word1 can be transformed into word2.


//? word1:
//? a → 2
//? b → 3
//? c → 1

//? word2:
//? a → 1
//? b → 2
//? c → 3

int main(){

  string word1 ,word2;
  getline(cin,word1);
  getline(cin,word2);

  if(word1.length() != word2.length()){
    cout << "false" << endl;
    return 0;
  }

  unordered_map<char, int> freq1;
  unordered_map<char, int> freq2;

  for(char ch : word1){
    freq1[ch]++;
  }
  
  for(char ch : word2){
    freq2[ch]++;
  }

  for(auto p : freq1){
    if(freq2.find(p.first) == freq2.end()){ //? Both the strings have have all characters in common , maybe in differnt freq
      cout << "false" << endl;
      return 0;
    }
  }

  vector<int> values1;
  vector<int> values2;

  for(auto p : freq1){
    values1.push_back(p.second); //? making a vector of the frequency values for string1
  }

  for(auto p : freq2){
    values2.push_back(p.second); //? making a vector of the frequency values for string2
  }

  sort(values1.begin(),values1.end()); //? We are sorting the vectors so that we can direclty compare them 
  sort(values2.begin(),values2.end());

  if(values1 == values2){
    cout << "true" << endl;
  }else{
    cout << "false" << endl;
  }

  return 0;
  
}