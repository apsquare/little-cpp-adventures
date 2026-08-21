/*
 * ROTATE AN ARRAY LEFT BY K (repeated single rotation)
 *
 * Problem    : Given an array of n integers and a number k, rotate the array
 *              to the left by k positions.
 * Input      : n, then n integers, then k
 * Output     : the rotated array
 * Idea       : Apply the rotate-left-by-one routine k times (k is reduced
 *              modulo n first).
 * Complexity : Time O(n * k)   Space O(1)
 */

#include<iostream>


void rotateLeftOnce(int arr[], int n){
  int first  = arr[0];
  for(int i=0;i<n-1;i++){
    arr[i]  = arr[i+1];
  }
  arr[n-1] = first;
}

using namespace std;
int main(){
  int n, k;
  cin >> n ;

  int arr[n];
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }

  cin >> k;
  k = k % n;

  for(int i=0;i<k;i++){
    rotateLeftOnce(arr,n);
  }

  for(int i=0;i<n;i++){
    cout << arr[i] << " ";
  }

  cout << endl;


}