/*
 * TRAPPING RAIN WATER (prefix / suffix maximum)
 *
 * Problem    : arr[i] is the height of a bar of width 1. Print how many
 *              units of water are trapped between the bars after it rains.
 * Input      : n, then n heights
 * Output     : total units of trapped water
 * Idea       : Precompute the tallest bar to the left and to the right of
 *              every index, then add up min(leftMax, rightMax) - height.
 * Complexity : Time O(n)   Space O(n)
 */

#include<iostream>

using namespace std;


int main(){

  int n ;
  cin >> n ;
  int arr[n];
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }

  int leftMax[n], rightMax[n];

  int leftMaxSoFar = 0;
  for(int i=0;i<n;i++){
    leftMax[i] = leftMaxSoFar;
    if(arr[i] > leftMaxSoFar){
      leftMaxSoFar = arr[i];
    }
  }

  int rightMaxSoFar = 0;
  for(int i=n-1;i>=0;i--){
    rightMax[i] = rightMaxSoFar;
    if(arr[i] > rightMaxSoFar){
      rightMaxSoFar = arr[i];
    }
  }

  int sum =0 ;
  for(int i=0;i<n;i++){
    int water = min(leftMax[i],rightMax[i]) - arr[i];
    if(water > 0 ){
      sum += water;
    }
  }

  cout << sum << endl;



}