/*
 * CONTAINER WITH MOST WATER (two pointers)
 *
 * Problem    : Given n vertical lines where heights[i] is the height of the
 *              line at index i, pick the two lines that with the x-axis
 *              hold the most water.
 * Input      : n, then n heights
 * Output     : the maximum area that can be stored
 * Idea       : Start at both ends. The area is min(height) * width, so the
 *              shorter line is the limit and moving it in is the only move
 *              that can improve the answer.
 * Complexity : Time O(n)   Space O(1)
 */

#include<iostream>


// Given an integer array heights, where height[i] represents the height of a vertical line at index i, choose two lines that, together with the x-axis, form a container that can hold the maximum amount of water. Return the maximum amount of water the container can store.

//? We need to make the area maximum min(arr[left],arr[right]) * (left- right)

using namespace std;

int main(){

  int n;
  cin >> n;
  int heights[n];

  for(int i=0;i<n;i++){
    cin >> heights[i];
  }

  int left  = 0;
  int right = n-1;
  int max_area = 0; //? This is the max water that can be stored


  while (left<=right)
  {
    int width = right -left;
    int height = min(heights[left],heights[right]);
    max_area = max(width*height,max_area);


    //? We simply try to change the index which has the smaller value 
    if(heights[left] < heights[right]){
      //? So, if the left index has the smaller value we move it one index ahead 
      left++;
    }else{
      right--;
    }

  }


  cout << max_area << endl;


  


}