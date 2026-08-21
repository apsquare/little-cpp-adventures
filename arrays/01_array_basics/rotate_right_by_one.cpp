/*
 * ROTATE AN ARRAY RIGHT BY ONE
 *
 * Problem    : Given an array of n integers, shift every element one
 *              position to the right and move the last element to the front.
 * Input      : n, then n integers
 * Output     : the rotated array
 * Idea       : Save arr[n-1], shift everything right, then place the saved
 *              value at index 0.
 * Complexity : Time O(n)   Space O(1)
 */

#include<iostream>


using namespace std;

int main(){
  int n;
  cin >> n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }

  int last = arr[n-1];
  for(int i=n-1;i>0;i--){
    arr[i] = arr[i-1];
  }

  arr[0]= last;

  for(int i=0;i<n;i++){
    cout << arr[i] << " ";
  }
  cout << endl;
}