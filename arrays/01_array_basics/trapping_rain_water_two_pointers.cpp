/*
 * TRAPPING RAIN WATER (two pointers)
 *
 * Problem    : arr[i] is the height of a bar of width 1. Print how many
 *              units of water are trapped between the bars after it rains.
 * Input      : n, then n heights
 * Output     : total units of trapped water
 * Idea       : Move the pointer standing on the shorter bar: that side's own
 *              running maximum is enough to decide the water above it.
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

  int left = 0;
  int right = n-1;
  int leftMax = 0;
  int rightMax = 0;
  int totalWater = 0;

  while(left <= right){
    if(arr[left] <= arr[right]){ // The bar on the left will be used to store water

      if(arr[left] >= leftMax){
        leftMax = arr[left]; // The current element is greater than every element to its left, so the difference is automatically 0
      }else{
        totalWater += leftMax - arr[left]; // An element to the left is taller than the current element, so water can be stored
      }

      left++;
      
    }else {

      if(arr[right] >= rightMax){
        rightMax = arr[right];
      }else{
        totalWater += rightMax - arr[right];
      }

      right--;

    }
  }

  cout << totalWater << endl;
  


}
