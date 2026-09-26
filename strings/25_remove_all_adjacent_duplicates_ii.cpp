#include<iostream>
#include<string>
#include<stack>
#include<utility>

using namespace std;

//! Problem: Given a string s and an integer k, repeatedly remove k adjacent identical characters until no more such groups exist.

//! Input:
//! s = "aa"
//! k = 3
//! Output:
//! "aa"

int main(){

  string s;
  int k;

  getline(cin,s);
  int n = s.length(); //? Here n is the string length 
  cin >> k;

  stack<pair<char,int>> freq_stack;

  
  for(int i=0;i<n;i++){

   if (!freq_stack.empty() && freq_stack.top().first == s[i]) {
    freq_stack.top().second++;

    if (freq_stack.top().second == k)
        freq_stack.pop();

  } else {
      freq_stack.push({s[i], 1});
  }


  }

  string result = "";
  while (!freq_stack.empty())
  {
    result = string(freq_stack.top().second,freq_stack.top().first) + result; //? string(count, character)
    freq_stack.pop();
  }

  cout << result << endl;










}