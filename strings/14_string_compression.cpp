#include<iostream>


using namespace std;

//! Problem: Compress consecutive repeating characters using the character followed by its count.
//! Input:  ['a','a','b','b','c','c','c']
//! Output: ['a','2','b','2','c','3']
//! No need to write 1 if the character occurs only once .

int main(){

  int num_characters;
  cin >> num_characters;

  char character_array[num_characters];

  for(int i=0;i<num_characters;i++){
    cin >> character_array[i];
  }


  char current_character  = character_array[0];
  int current_character_count =1 ;

  string output_string = "" ;
  output_string += current_character;

  for(int i=1;i<num_characters;i++){

    if(character_array[i] == current_character){
      current_character_count++;
    }else{
      if(current_character_count != 1){
        output_string += to_string(current_character_count);
      }
      current_character_count = 1;
      current_character = character_array[i];
      output_string += current_character;
    }
    
  }

  if(current_character_count != 1){
        output_string += to_string(current_character_count);
  }

  cout << output_string << endl;


}