#include<iostream>
#include<unordered_map>
#include<string>
//! Problem: Given two strings ransomNote and magazine, check whether ransomNote can be constructed using characters from magazine.

//? ransomNote = "aab"
//? magazine = "baaac"

using namespace std;


int main(){

  string ransomNote;
  getline(cin,ransomNote);
  int ransomeNoteLength = ransomNote.length();

  string magazine;
  getline(cin,magazine);
  int magazineLength = magazine.length();

  unordered_map<char,int> ransomNote_freq;

  for(int i=0;i<ransomeNoteLength;i++){
    ransomNote_freq[ransomNote[i]] ++;
  }

  for(int i=0;i<magazineLength;i++){
    ransomNote_freq[magazine[i]]--;
  }

  for(auto &item : ransomNote_freq){
    if(item.second >0 ){
      cout << "Not Possible" << endl;
      return 0;
    }
  }

  cout << "Possible" << endl;


}