#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

//! Problem: Check whether characters in string s can be consistently mapped to characters in string t.
//! s = "egg"
//! t = "add"
//! Output: true


//? There should be like a one to one relation

int main(){

  string s ,t ;
  getline(cin,s);
  getline(cin,t);

  if(s.length() != t.length()){
    cout << "False" << endl;
    return 0;
  }

  unordered_map<char,char> checks; //? This checks the relation from the 's' side
  unordered_map<char,char> checkt; //? This checks the relation from the 't' side

  for(int i=0;i<s.length();i++){
    if(checks[s[i]] == '\0' && checkt[t[i]] == '\0'){
      checks[s[i]] = t[i];
      checkt[t[i]] = s[i];
    }else{
      if(checks[s[i]] != t[i] || checkt[t[i]] != s[i]){
          cout << "False" << endl;
          return 0;
      }
      
    }
  }

  cout << "True" << endl;
 
}
