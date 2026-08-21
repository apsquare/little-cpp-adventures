/*
 * INSERTION SORT
 *
 * Problem    : Sort an array of n integers in ascending order.
 * Input      : n, then n integers
 * Output     : the sorted array, one element per line
 * Idea       : Keep the left part sorted and push each new element back into
 *              its place.
 * Complexity : Time O(n^2), O(n) when already sorted   Space O(1)   Stable
 */

#include<iostream>

using namespace std;

//? Insertion Sort 
//*The main idea is that we insert he next elements in the left side which is sorted 

int main(){

  int n;
  cin >> n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }
 
  for(int i=1;i<n;i++){//* First element is always sorted 
    for(int j=i;j>0;j--){
      if(arr[j] < arr[j-1]){
        int temp = arr[j];
        arr[j] = arr[j-1];
        arr[j-1] = temp;
      }
    }
  }

  for(int i=0;i<n;i++){
    cout << arr[i] << endl;
  }



}