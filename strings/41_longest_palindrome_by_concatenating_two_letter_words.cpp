#include<iostream>
#include<string>
#include<unordered_map>
#include <algorithm>

using namespace std;

//! Problem: You are given an array of strings `words`.
//! Every string contains exactly two lowercase English letters.
//! Choose some of the words and concatenate them in any order so that
//! the resulting string is a palindrome.
//! Return the length of the longest palindrome you can build.

//! Input:
//! words = {"lc", "cl", "gg"}
//! Output: 6
//! Explanation: "lc" + "gg" + "cl" = "lcggcl"

//? aa bb aa   

//? aa aa aa bb bb bb  --> bb aa aa aa bb

int main(){

  string arr[] = {"lc", "cl", "gg"};
  int n = sizeof(arr)/sizeof(arr[0]); 
  int total_words = 0;
  bool center_available =false;

  unordered_map<string,int> freq;
  for(string word : arr){
    freq[word]++;
  }

  for(auto p : freq){
    string current_word = p.first;
    string reversed_word = current_word;
    reverse(reversed_word.begin(),reversed_word.end());

    if(reversed_word == current_word){
      int count = freq[current_word];
      total_words += (count/2) * 2; //? We can use only the even number of words to form a palindrome
      if(count % 2 == 1){
        center_available = true; //?This odd group can be the center 
      }
    }else {
      if(freq.find(reversed_word) != freq.end()){
        if(current_word < reversed_word){
          //? ab -> 4 times , ba -> 2 times , we can use only 2 pairs to create the palindrome 
          int count = min(freq[current_word], freq[reversed_word]);
          total_words += count * 2; 
      }
    }

  }
  }

 if(center_available){
  total_words += 1;
 }

 cout << total_words * 2 << endl; //? Each word has length 2, so multiply by 2 to get the total length of the palindrome

}