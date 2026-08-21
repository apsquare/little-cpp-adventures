/*
 * SQUARES OF A SORTED ARRAY (two pointers)
 *
 * Problem    : Given an array of n integers sorted in non-decreasing order,
 *              print the square of each number, also sorted in
 *              non-decreasing order.
 * Input      : n, then n sorted integers (negatives allowed)
 * Output     : the n sorted squares, one per line
 * Idea       : The largest square is always at one of the two ends, so
 *              compare the absolute values and fill the result from the
 *              back forwards.
 * Complexity : Time O(n)   Space O(n)
 */

#include<iostream>
#include<cstdlib>

using namespace std;

//! Given an integer array sorted in non-decreasing order, return an array containing the square of each number, also sorted in non-decreasing order.
//? arr    = [-4, -1, 0, 3, 10] -- > Here we are not sure about the smallest values but we know that the largest squared values will appear at one of the ends 
//? In a sorted array with negatives, the largest square must come from either the far left or far right.


int main(){

  int n;
  cin >> n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }

  int squared_array[n];

  int left = 0;
  int right = n-1;
  int index = n-1;//? We will start filing from the end

 while(left <= right){
   if(abs(arr[left]) > abs(arr[right])){
    squared_array[index--] = arr[left] * arr[left];
    left ++;
  }else{
    squared_array[index--]  = arr[right] * arr[right];
    right--;
    //? even if they are equal we will just move one of the indices (here , right) because we do not want to skip the duplicate squares created 
  }

  
 }

 for(int i=0;i<n;i++){
    cout << squared_array[i] << endl;
  }



 







}