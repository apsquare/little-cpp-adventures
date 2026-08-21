/*
 * TRAPPING RAIN WATER (brute force)
 *
 * Problem    : arr[i] is the height of a bar of width 1. Print how many
 *              units of water are trapped between the bars after it rains.
 * Input      : n, then n heights
 * Output     : total units of trapped water
 * Idea       : For every bar, scan both sides for the tallest bar; the water
 *              above it is min(maxLeft, maxRight) - height.
 * Complexity : Time O(n^2)   Space O(1)
 */

#include<iostream>
#include<climits>

using namespace std;

int main(){

  int n ;
  cin >> n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }

  int totalWater  = 0 ;

  for(int i=0;i<n;i++){
    int maxLeft = 0;
    int maxRight = 0;

    for(int j=0;j<i;j++){
      maxLeft = max(maxLeft,arr[j]);
    }

    
    for(int j=i+1;j<n;j++){
      maxRight = max(maxRight,arr[j]);
    }

     int water = min(maxLeft,maxRight)-arr[i];
     if(water> 0)
      totalWater += water;

  }

  cout << totalWater << endl;

}