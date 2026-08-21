/*
 * LEADERS IN AN ARRAY (suffix maximum)
 *
 * Problem    : An element is a leader if it is greater than every element to
 *              its right. Print all the leaders.
 * Input      : n, then n integers
 * Output     : the leaders, printed right-to-left
 * Idea       : Walk from the right keeping the largest value seen so far;
 *              anything bigger than it is a leader.
 * Complexity : Time O(n)   Space O(1)
 */

#include<iostream>

using namespace std;

int main(){

  int n ;
  cin >> n;
  int arr[n];
  
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }

  int largestRight = arr[n-1];
  cout << largestRight << " ";

  for(int i=n-2;i>=0;i--){
    if(arr[i] > largestRight){
      cout << arr[i] << " ";
      largestRight = arr[i];
    }
  }









}