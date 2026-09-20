#include<iostream>
#include<string>

using namespace std;

//! Question: Given a string, find the first character that appears only once in it.
//! Example: "aabbcdc" -> 'd'  (a, b and c repeat; d is the first one that appears exactly once)

int main(){
  string s;
  getline(cin,s);
  int n = s.length();


  int freq[256] = {0};

  for(int i=0;i<n;i++){
    freq[s[i]]++;
  }

  for(int i=0;i<n;i++){
    if(freq[s[i]] == 1){
      cout << s[i] << endl;
      break;
    }
  }


}