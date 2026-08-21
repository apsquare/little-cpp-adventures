/*
 * CHECK IF AN ARRAY IS SORTED
 *
 * Problem    : Given an array of n integers, check whether it is sorted in
 *              non-decreasing (ascending) order.
 * Input      : n, then n integers
 * Output     : "ascending" or "not ascending"
 * Idea       : One pass, comparing every element with the one before it.
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

  for(int i=1;i<n;i++){
    if(arr[i] < arr[i-1]){
      cout << "not ascending" <<endl;
      return 0;
    }
  }

  cout << "ascending" << endl;

}