#include<iostream>
#include<string>

using namespace std;

//! Problem: Given a string s, return true if it can become a palindrome after deleting at most one character.

int isPalindrome(string s , int left , int right){
  while(left < right){
    if(s[left] != s[right]){
      return false;
    }
    left++;
    right--;
  }
  return true;
}


int main(){

  string s;
  getline(cin,s);
  
  int n = s.length();

  int left = 0;
  int right = n-1;
  
  while(left < right){
    if(s[left] == s[right]){
       left++;
       right--;
    }else{
      if(isPalindrome(s,left+1,right) || isPalindrome(s,left,right-1)){
        cout << "True" << endl;
      }else{
        cout << "False" << endl;
        
      }
      return 0;
    }
  }

  cout << "True" << endl;
  return 0;

}

