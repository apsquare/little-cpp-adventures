#include<iostream>
#include<string>

using namespace std;

//! Problem:
//! Given a string s, return the longest non-empty prefix of s which is also a suffix of s.
//! The prefix and suffix must NOT be the entire string.

//! Input:
//! s = "level"
//! Output: "l"

//! Explanation:
//! Prefix "l" == Suffix "l"

//! Input:
//! s = "ababab"
//! Output: "abab"

//! Prefix: "abab"
//! Suffix: "abab"

int main(){

  string str;
  getline(cin,str);
  int n = str.length();

  string longest_prefix = "";

  for(int i=1;i<n;i++){
    string prefix = str.substr(0,i);

    // This will consider the last i elements of the string as the suffix
    string suffix = str.substr(n-i);
    if(prefix == suffix && prefix.length() < n){
      longest_prefix = prefix;
    }
  }

  cout << longest_prefix << endl;
  return 0;



}