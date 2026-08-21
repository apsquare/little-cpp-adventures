/*
 * CEIL AND FLOOR IN A SORTED ARRAY
 *
 * Problem    : Given a sorted array of n integers and a target, print the
 *              ceil (the smallest value >= target) and the floor (the
 *              largest value <= target).
 * Input      : n, then n sorted integers, then target
 * Output     : ceil and floor on one line, -1 when a value does not exist
 * Idea       : Two binary searches: one keeps the last value <= target, the
 *              other the last value >= target.
 * Complexity : Time O(log n)   Space O(1)
 */

#include<iostream>


using namespace std;

int main(){

  // Take input
  int n , target;
  cin >> n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin >> arr[i];  
  }
  cin >> target;


  int floorValue = -1;
  int left = 0 , right = n-1;
  while (left<= right)
  {
    int mid = left + (right-left)/2;
    if(arr[mid] <= target){
      floorValue = arr[mid];
      left = mid+1;
    }else{
      right = mid - 1;
    }
  }


  int ceilValue = -1;
  left =0 , right = n-1 ;
  while (left <= right )
  {
   int mid = left + (right-left)/2;
   if(arr[mid] >= target){
    right = mid -1;
    ceilValue = arr[mid];
   }else{
    left = mid + 1;
   }
  }


  cout << ceilValue << " " << floorValue << endl;
  

 




}
