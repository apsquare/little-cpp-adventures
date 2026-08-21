/*
 * ROTATE AN ARRAY LEFT BY ONE
 *
 * Problem    : Given an array of n integers, shift every element one
 *              position to the left and move the first element to the end.
 * Input      : n, then n integers
 * Output     : the rotated array
 * Idea       : Save arr[0], shift everything left, then place the saved
 *              value at the end.
 * Complexity : Time O(n)   Space O(1)
 * TODO       : the shifting loop runs to i = n-1 and reads arr[n], which is
 *              out of bounds. It should stop at i < n-1.
 */

#include<iostream>

using namespace std;

int main(){

  // Take user input
  int n;
  cin >> n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }
  int first = arr[0];


  for(int i=0;i<n;i++){
    arr[i] = arr[i+1];
  }

  arr[n-1] = first;

  for(int i=0;i<n;i++){
    cout << arr[i];
  }


  




}
