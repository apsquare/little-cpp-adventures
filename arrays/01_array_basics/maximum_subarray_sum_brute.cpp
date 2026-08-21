/*
 * MAXIMUM SUBARRAY SUM (prefix sums, brute force)
 *
 * Problem    : Given an array of n integers, print the largest sum
 *              obtainable from a contiguous subarray.
 * Input      : n, then n integers
 * Output     : the maximum subarray sum
 * Idea       : Build a prefix sum array, then test every (i, j) pair in O(1)
 *              each.
 * Complexity : Time O(n^2)   Space O(n)
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

  // Create the prefix array
  int prefixSum[n];
  prefixSum[0] = arr[0];
  for(int i=1;i<n;i++){
    prefixSum[i] = prefixSum[i-1] + arr[i];
  }

  int maxSum = INT_MIN;
  for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
      int sum ; 
      if(i == 0) {
        sum = prefixSum[j];
      }else {
        sum = prefixSum[j] - prefixSum[i-1];  
      }

      if(sum > maxSum){
        maxSum = sum;
      }
    
    }
  }

  cout << maxSum << endl;








}
