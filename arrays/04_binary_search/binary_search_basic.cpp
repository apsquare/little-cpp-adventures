/*
 * BINARY SEARCH - first occurrence
 *
 * Problem    : Given a sorted array of n integers and a target, print the
 *              index of the first occurrence of the target, or -1 if it is
 *              not present.
 * Input      : n, then n sorted integers, then target
 * Output     : index of the first occurrence, else -1
 * Idea       : Standard binary search, but on a match keep searching the
 *              left half instead of stopping.
 * Complexity : Time O(log n)   Space O(1)
 */

#include<iostream>


using namespace std;

int main(){

  int n  ,target ;

  cin >> n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }
 
  cin >> target;

  int left = 0 , right = n-1;
  int currentIndex  = -1;
  while (left <= right)
  { 
    int mid = (left + right)/2;
    if(arr[mid] == target){
     currentIndex =mid;
     right = mid-1;
    }else if(target < arr[mid]){
      right = mid -1 ;
    }else if (target > arr[mid])
    {
      left = mid+1;
    }
  }

  cout << currentIndex <<endl;
  


}