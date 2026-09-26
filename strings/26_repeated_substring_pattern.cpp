#include<iostream>
#include<string>

using namespace std;

//! Problem: Given a string s, determine whether it can be formed by repeating one of its substrings multiple times.

//! Input:  "abab"
//! Output: true
//! "ab" + "ab" = "abab"

int main(){

  string s;
  getline(cin,s);
  int n = s.length();

  for(int i=1;i<=n/2;i++){ //? Here i represents the length of the pattern considered 

    if(n%i !=0 ){
      continue;
    }
    
    bool found = true;

    string pattern = s.substr(0,i);
    for(int j =0 ;j<n;j++){ //? Here j represents the current index of the original string s
      if(s[j] != pattern[j%i]){
        found = false;
        break;
      }
    }

    if(found){
      cout << "True" << endl;
      return 0;
    }

  }
  cout << "false" << endl;
}