/*
 * MAJORITY ELEMENT (brute force)
 *
 * Problem    : Given an array of n integers, print the element that appears
 *              more than n/2 times, or -1 if there is none.
 * Input      : n, then n integers
 * Output     : the majority element, else -1
 * Idea       : Count the occurrences of every element with a nested loop.
 * Complexity : Time O(n^2)   Space O(1)
 */

#include<iostream>

using namespace std;

int main(){
  int n  ;
  cin >> n;
  int arr[n];

  for(int i=0;i<n;i++){
    cin >> arr[i];
  }

  for(int i=0;i<n;i++){
    int currentCount =0 ;
    for(int j=0;j<n;j++){
      if(arr[j] == arr[i]){
        currentCount++;
        if(currentCount > n/2){
          cout << arr[i] << endl;
          return 0;
        }
      }
    }
  }

  cout << -1 << endl;

  
}