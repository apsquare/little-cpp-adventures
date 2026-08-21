/*
 * MAXIMUM SUBARRAY SUM (Kadane's algorithm)
 *
 * Problem    : Given an array of n integers, print the largest sum
 *              obtainable from a contiguous subarray.
 * Input      : n, then n integers
 * Output     : the maximum subarray sum
 * Idea       : At each element decide whether to extend the running subarray
 *              or start a fresh one: current = max(current + arr[i],
 *              arr[i]).
 * Complexity : Time O(n)   Space O(1)
 */

#include<iostream>
#include<climits>

using namespace std;

int main(){

   // Take the number as input
  int n ;
  cin >>  n;
  int arr[n] ;
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }

 

  // Kadane's algo

  int currentSum = arr[0];
  int maxSum = arr[0];
  for(int i=1;i<n;i++){
    currentSum = max(currentSum + arr[i],arr[i]);
    maxSum = max(currentSum,maxSum);
  }

  cout << maxSum  << endl;




}
