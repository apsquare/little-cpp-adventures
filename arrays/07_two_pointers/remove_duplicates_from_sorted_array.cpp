/*
 * REMOVE DUPLICATES FROM SORTED ARRAY (two pointers)
 *
 * Problem    : Given a sorted array of n integers, remove the duplicates
 *              in place so every unique value appears once, keeping order.
 * Input      : n, then n sorted integers
 * Output     : the number of unique elements
 * Idea       : left marks the last unique slot, right scans ahead. When
 *              right finds a new value it is written to ++left, so the
 *              prefix arr[0..left] stays unique.
 * Complexity : Time O(n)   Space O(1)
 */

#include<iostream>


using namespace std;

//!Given a sorted array, remove the duplicates in-place so that each unique element appears only once.
//!Return/print the number of unique elements.

int main(){


  int n;
  cin >> n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }


  //? If there are no elements then just return 0
  if(n==0){
    cout << 0 << endl;
    return 0;
  }


  int left = 0 ,right = 1 , unique_elements = 1; //?The first element is already unique
  while(right < n){
    if(arr[left] == arr[right]){
      right++;
    }else{
      // unique_elements++;
      left++ ; //?This is beacause this was the last element that was already unique so we will put the new element in the new index
      arr[left] = arr[right++];
    }
  }

  // cout << unique_elements << endl;
  cout << left + 1 << endl; // ? Indices start from 0





}