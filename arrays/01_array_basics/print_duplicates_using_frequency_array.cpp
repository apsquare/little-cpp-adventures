/*
 * PRINT ALL DUPLICATE ELEMENTS
 *
 * Problem    : Given an array of n integers in the range 0..999, print every
 *              element that appears more than once. Print each duplicate
 *              only once, in increasing order.
 * Input      : n, then n integers
 * Output     : the duplicate values, one per line, or -1 when there are none
 * Idea       : Count into a frequency array, then print every value whose
 *              count is > 1.
 * Complexity : Time O(n + 1000)   Space O(1000)
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

  int freq[1000] = {0};
  for(int i=0;i<n;i++){
    freq[arr[i]]++;
  }
  bool found = false;
  for(int i=0;i<1000;i++){
    if(freq[i] > 1 ){
      found = true;
      cout << i << endl;
    }
  }

  if(!found) 
    cout << -1 << endl;



}