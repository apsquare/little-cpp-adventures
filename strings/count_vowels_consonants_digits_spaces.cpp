#include<iostream>
#include<string>
#include<cctype>

//! Question: Given a string, count the number of vowels, consonants, digits, and spaces.

using namespace std;

int main(){

  string s;
  getline(cin ,s);

  int n = s.length();
  int vowels = 0 , consonants = 0 , digits = 0 , spaces = 0;
  string v_count = "aeiou";




  for(int i=0;i<n;i++){
    if(isalpha(s[i])){
      if(v_count.find(tolower(s[i])) != string::npos){
        vowels++;
      }else{
        consonants++;
      }
    }else if(isdigit(s[i])){
      digits++;
    }else if(isspace(s[i])){
      spaces++;
    }
  }



  cout << "Vowels: " << vowels << endl;
  cout << "Consonants: " << consonants << endl;
  cout << "Digits: " << digits << endl;
  cout << "Spaces: " << spaces << endl; 

}