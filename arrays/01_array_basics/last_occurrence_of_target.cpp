/*
 * LAST OCCURRENCE OF AN ELEMENT
 *
 * Problem    : Given an array of n integers and a target, print the index of
 *              the last occurrence of the target, or -1 if it is not
 *              present.
 * Input      : n, then n integers, then target
 * Output     : index of the last match, else -1
 * Idea       : Scan from the right end and stop at the first match found.
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

  int target ;
  cin >> target;
  
  int lastIndex = -1;

  for(int i=n-1;i>=0;i--){
    if(arr[i] == target){
      lastIndex = i;
      break;
    }
  }

  cout << lastIndex << endl;
    // If no element is present, return -1.



}
