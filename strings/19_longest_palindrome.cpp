#include<iostream>
#include<string>
#include<unordered_map>

//! Problem: Given a string containing uppercase and lowercase letters, find the maximum length of a palindrome that can be built using those characters.

//? aba --> At max one character can appear single 

using namespace std;

int main(){

  string str;
  getline(cin,str);
  int str_length = str.length();


  unordered_map<char,int> freq;

  for(int i=0;i<str_length;i++){
    freq[str[i]]++;
  }

  int singular_count = 0;
  for(auto &item : freq){
    if(item.second % 2 != 0){
      singular_count++;
    }
  }

  if(singular_count>1){
    cout << str_length - singular_count +1 << endl; //? We can have atmost one singular element that will appearn in the middle 
  }else{
    cout << str_length << endl; //? If all the elements are present in pairs then the entire string can be converted into a palindrome 
  }
  



}
