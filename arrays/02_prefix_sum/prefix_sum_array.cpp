/*
 * PREFIX SUM ARRAY - single range query
 *
 * Problem    : Given an array of n integers and one query (L, R), print the
 *              sum of the elements from index L to index R, both inclusive.
 * Input      : n, then n integers, then L and R (0-based)
 * Output     : the sum of arr[L..R]
 * Idea       : prefixSum[i] = arr[0] + ... + arr[i], so a range sum becomes
 *              a subtraction.
 * Complexity : Time O(n) to build, O(1) per query   Space O(n)
 */

#include<iostream>


int main(){


  int n ;
  std::cin >> n ;
  int arr[n] , prefixSum[n];

  for(int i=0;i<n;i++){
    std::cin >> arr[i];
  }

  prefixSum[0] = arr[0]; 
  for(int i=1;i<n;i++){
    prefixSum[i] = prefixSum[i-1] + arr[i];
  }

  int L , R;
  std::cin >> L >>  R;
  int sum = prefixSum[R] -prefixSum[L]  + arr[L];
  std::cout << sum << std::endl;  


 

}