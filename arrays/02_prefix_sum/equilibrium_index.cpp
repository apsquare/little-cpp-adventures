/*
 * EQUILIBRIUM INDEX
 *
 * Problem    : Find an index where the sum of all the elements strictly to
 *              its left equals the sum of all the elements strictly to its
 *              right.
 * Input      : n, then n integers
 * Output     : the first equilibrium index, or -1 if none exists
 * Idea       : With a prefix sum, leftSum = prefix[i-1] and rightSum =
 *              prefix[n-1] - prefix[i].
 * Complexity : Time O(n)   Space O(n)
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

  // Calculate the prefix sum

  int prefixSum[n];

  prefixSum[0] = arr[0];
  for(int i=1;i<n;i++){
    prefixSum[i] = prefixSum[i-1] + arr[i];
  }

  for(int i=0;i<n;i++){
    int leftSum = i ==0 ? 0 : prefixSum[i-1];
    int rightSum = prefixSum[n-1] - prefixSum[i];
    if(leftSum == rightSum){
      cout << i << endl;
      return 0;
    }
      
  }

  cout << -1 << endl;

  

}
