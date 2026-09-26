#include<iostream>
#include<string>
#include <unordered_map>

using namespace std;

//! Pattern: String + Character Mapping
//! You are given a string key and a string message.
//! The key defines a substitution alphabet:
//! - Scan key from left to right.
//! - Ignore spaces.
//! - The first unique character you encounter maps to 'a'.
//! - The next new character maps to 'b', then 'c', and so on.
//! - Use this mapping to decode message.
//! - Spaces in message remain spaces.


int main(){
  string key , message;
  getline(cin,key);
  getline(cin,message);

  unordered_map<char,char> character_map;
  
  char mapping_value = 'a';
  for(int i=0;i<key.length();i++){
    if(character_map.find(key[i]) == character_map.end()){ //? This character has appeared for the first time in the key so map it 
      if(key[i] != ' '){
        character_map[key[i]] = mapping_value++;
      }
    }
  }


  for(int i=0;i<message.length();i++){
    if(message[i] != ' '){
      cout << character_map[message[i]]  ;
    }else{
      cout << " " ;
    }
  }

  cout << endl;



}