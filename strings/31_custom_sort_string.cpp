#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

//! Problem: You are given two strings order and s.
//! All characters in order are unique and represent a custom ordering of characters.
//! Rearrange the characters of s so that the characters that also appear in s follow the same relative order specified by order.
//! Characters of s that do not appear in order may be placed anywhere in the result.
//* There might be characters of order that are not present in s

//! Input:
//! order = "cba"
//! s     = "abcd"

//! Possible Output:
//! "cbad"

int main(){
  string order , s;
  getline(cin,order);
  getline(cin,s);

  unordered_map<char,int> freq;

  for(int i=0;i<s.length();i++){
    freq[s[i]]++;
  }

  string result = "";

  for(int i=0;i<order.length();i++){
    if(freq[order[i]] > 0){
      result += string(freq[order[i]], order[i]); //* !ven if the chanracter freq is more in s we will keep all of them and not just keep the character once 
      freq[order[i]]  = 0;
    }
  }

  for(auto p : freq){
    result += string(p.second,p.first);
  }

  cout << result << endl;

}
