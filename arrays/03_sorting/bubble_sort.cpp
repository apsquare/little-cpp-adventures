/*
 * BUBBLE SORT
 *
 * Problem    : Sort an array of n integers in ascending order.
 * Input      : n, then n integers
 * Output     : the sorted array, one element per line
 * Idea       : Repeatedly compare neighbours and swap them when they are out
 *              of order, so the largest unsorted value bubbles to the end of
 *              each pass.
 * Complexity : Time O(n^2)   Space O(1)   Stable
 */

#include<iostream>


using namespace std;

//* Bubble sort repeatedly compares neighbouring elements.
//* If they are in the wrong order, it swaps them.
//* After every pass, the largest unsorted element "bubbles up" to the end.

int main(){

  int n;
  cin >> n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }

  //* The unsorted part of the array ends at index i.
  for(int i=n-1;i>=0;i--){
    // Compare each pair of neighbouring elements in the unsorted part.
    for(int j=0;j<i;j++){
      if(arr[j] > arr[j+1]){
        //* Swap the pair in case the earlier one is larger 
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp; 
      }
    }
  }

 //* print the sorted array
  for(int i=0;i<n;i++){
    cout << arr[i] << endl;
  }



}
