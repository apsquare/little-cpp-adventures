/*
 * MULTIPLE RANGE SUM QUERIES
 *
 * Problem    : Given an array of n integers and q queries, each with indices
 *              L and R, print the sum of arr[L..R] for every query.
 * Input      : n, then n integers, then q, then q pairs of L and R (0-based)
 * Output     : one sum per query
 * Idea       : Build the prefix sum once; every query is prefixSum[R] -
 *              prefixSum[L-1].
 * Complexity : Time O(n + q)   Space O(n)
 */

#include<iostream>


using namespace std;

int main(){
  int n;
  std::cin >> n;
  int arr1[n];
  for(int i=0;i<n;i++){
    cin >> arr1[i];
  }

  int prefixSum[n];

  prefixSum[0] = arr1[0];
  for(int i=1;i<n;i++){
    prefixSum[i] = prefixSum[i-1] + arr1[i];
  }

  

  int q ;
  cin >> q;
 
  for(int i=0;i<q;i++){
    int L , R;
    cin >> L >> R ;
    if(L==0){
      cout << prefixSum[R] <<endl;
    }else{
      cout << prefixSum[R] - prefixSum[L-1] << endl;
     }
  }


  cout << endl;






}