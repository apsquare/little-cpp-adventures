#include<iostream>
#include<string>


using namespace std;


//! Question: Given a string, convert every lowercase letter to uppercase and every uppercase letter to lowercase. Leave digits, spaces, and symbols unchanged.

int main(){
  string s;
  getline(cin,s);
  int n = s.length();
  
  for(int i=0;i<n;i++){
    if(islower(s[i])){
      s[i] = toupper(s[i]);
    }else if(isupper(s[i])){
      s[i] = tolower(s[i]);
    }
  }
  cout << s << endl;

}