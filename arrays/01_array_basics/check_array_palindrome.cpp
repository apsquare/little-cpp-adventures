/*
 * CHECK IF AN ARRAY IS A PALINDROME
 *
 * Problem    : Given an array of n integers, check whether it reads the same
 *              forwards and backwards.
 * Input      : n, then n integers
 * Output     : "Palindrome" or "Not a Palindrome"
 * Idea       : Two pointers from both ends, moving inwards while the values
 *              match.
 * Complexity : Time O(n)   Space O(1)
 */

#include<iostream>

using namespace std;

int main(){

  int n ;
  cout << "Enter the number of elements " << endl;
  cin >> n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }
  bool isPalindrome = true;
  int left = 0 , right = n-1;
  
  while(left < right){
    if(arr[left] != arr[right]){
      isPalindrome = false;
      break;
    }
    left ++;
    right--;
  }

  if(isPalindrome)
    cout << "Palindrome" << endl;
  else 
    cout << "Not a Palindrome" << endl;


}