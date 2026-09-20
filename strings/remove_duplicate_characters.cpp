#include<iostream>
#include<string>
#include<unordered_map>


using namespace std;


//! Question: Given a string, remove duplicate characters while keeping the first occurrence of every character in its original order.


int main(){
  string s;
  getline(cin,s);
  int n = s.length();

  string result = "";
  unordered_map<char,bool> seen;

  for(int i=0;i<n;i++){
    if(seen.find(s[i]) == seen.end()){
      result += s[i];
      seen[s[i]] = true;
    }
  }


  cout << result << endl;



}
