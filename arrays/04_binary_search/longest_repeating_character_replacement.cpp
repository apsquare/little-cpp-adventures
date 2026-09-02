#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

//! Question: You are given a string s and an integer k. You can replace at most k characters in a substring so that all characters in that substring become the same. Find the maximum possible length of such a substring.
//! Example: s = "AABABBA", k = 1 → output 4. One valid window is "AABA"; replace B with A to get "AAAA".


int main(){

  
  string s;
  int k ;
  getline(cin,s);
  cin >> k;

  int left =0;
  int right =0 ;
  int max_length =0 ;  //? Length of the longest valid window found so far
  int max_freq = 0; //? Highest frequency of a single character seen in the current/best window
  unordered_map<char,int> freq;

  
  while(right<s.length()){
    freq[s[right]]++;
    max_freq = max(max_freq,freq[s[right]]);

    if((right-left+1 ) - max_freq > k){
      freq[s[left]]--;
      left++;
    }

      //? The window is now valid 
      max_length = max(max_length,right-left+1);

    right++;
    
  }

  cout << max_length << endl;


}