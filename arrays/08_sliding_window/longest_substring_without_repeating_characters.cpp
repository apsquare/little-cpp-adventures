#include<iostream>
#include<unordered_map>

using namespace std;
//! Longest Substring Without Repeating Characters
//! Question: Given a string s, find the length of the longest contiguous substring that contains no repeating characters.

int main(){

  string s;
  cin >> s;
  int n  = s.length();

  unordered_map<char,int> freq;

  int left = 0 ;
  int right = 0;
  int longest = 0;

  while(right < n){
    freq[s[right]]++;

    while(freq[s[right]] > 1){
      freq[s[left]]--;
      left++;
    }

    longest = max(longest,right-left+1);
    right++;
  }

  cout << longest << endl;


}