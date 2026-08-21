/*
 * MOVE ZEROES (two pointers)
 *
 * Problem    : Given an array of n integers, move every 0 to the end while
 *              keeping the relative order of the non-zero elements. The
 *              array must be modified in place, without a second array.
 * Input      : n, then n integers
 * Output     : the rearranged array, one value per line
 * Idea       : left sits on the first zero, right scans ahead for the next
 *              non-zero value and the two are swapped.
 * Complexity : Time O(n)   Space O(1)
 */

#include<iostream>

using namespace std;


//! Given an integer array arr, move all 0s to the end of the array while maintaining the relative order of the non-zero elements. You must modify the array in-place without creating another array.

int main(){


  //?Taking the input
  int n;
  cin >> n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }

  if(n == 0){
    return 0;
  }



  int left = 0;
  int right = 1;

  while(right < n && left <n){
    if(arr[left] ==0 && arr[right] != 0){
    int temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
    left ++;//? In case we find a 0 on the left index we swap it with the next non zero element that we get
    }

    if(arr[left] != 0 ){ //? If the left index is not at 0 move forward
      left ++;
    }

    right ++;


}


    for(int i=0;i<n;i++){
      cout << arr[i] << endl;
    }


}