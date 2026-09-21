#include<iostream>
#include<string>


using namespace std;
//! Problem: Given strings s and t, check whether s is a subsequence of t. A subsequence keeps the same order, but characters don't need to be adjacent.
 
int main(){

  string s, t;
  getline(cin,s);
  getline(cin,t);
  int n = s.length();
  int m = t.length();


  int i=0,j=0;
  while(i<n&& j<m){
    if(s[i] == t[j]){
      i++;
    }
    j++;

  }

  if(i == n){
    cout << "True" << endl;
  }else{  
    cout << "False" << endl;
  } 

  




}