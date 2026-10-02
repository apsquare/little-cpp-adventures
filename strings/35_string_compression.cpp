#include<iostream>
#include<string>

using namespace std;

//* Pattern: Two Pointers + In-place String Modification

//! Problem: Given an array of characters, compress consecutive repeating
//! characters in-place.
//! Write each character once, followed by its frequency if the frequency
//! is greater than 1.
//! If the frequency has multiple digits, write each digit separately.
//! Return the length of the compressed array.

//! Input:  ['a','a','b','b','c','c','c']
//! Output: ['a','2','b','2','c','3']
//! Return: 6

//! Input:
//! ['a','b','b','b','b','b','b','b','b','b','b','b','b']
//! Compressed:
//! ['a','b','1','2'] --> 12 will be stored as two different characters
//! Return: 4


int main(){
  vector<char> chars = {'a','a','b','b','c','c','c'};

  int read = 0, write = 0 ;
  int current_count = 0;
  char current_character ;

  while(read < chars.size()){
    if(current_count == 0){
      current_character = chars[read++];
      current_count++;
      continue;
    }

    if(current_character != chars[read]){
      chars[write++] = current_count;
      current_count = 0;
    }else{
      current_count++;
    }

    read++;

  }


  


}
