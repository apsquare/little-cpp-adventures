/*
 * LOWER BOUND
 *
 * Problem    : Given a sorted array of n integers and a target, print the
 *              index of the first element that is >= target, or n if there
 *              is no such element.
 * Input      : n, then n sorted integers, then target
 * Output     : the lower bound index
 * Idea       : Binary search, remembering every candidate index and
 *              shrinking to the left.
 * Complexity : Time O(log n)   Space O(1)
 * TODO       : the condition moves left on arr[mid] <= target, so this
 *              currently returns the UPPER bound (first element > target).
 *              Use arr[mid] < target to get the lower bound.
 */

#include<iostream>

using namespace std;

int main(){
    int n ,target;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
      cin >> arr[i];
    }
    cin >> target;


    int left = 0 ,right = n-1;
    int lastOption = n;

    while(left <= right){
      int mid = left + (right-left)/2;

      if(arr[mid] > target){
        lastOption = mid;
        right = mid -1;
      }

      else if(arr[mid] <= target){
        left = mid + 1;
      }

    }


    cout << lastOption << endl;
    



}