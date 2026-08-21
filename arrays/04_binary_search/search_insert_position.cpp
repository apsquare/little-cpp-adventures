/*
 * SEARCH INSERT POSITION
 *
 * Problem    : Given a sorted array of n integers and a target, print the
 *              index of the target, or the index where it would be inserted
 *              to keep the array sorted.
 * Input      : n, then n sorted integers, then target
 * Output     : the index of the target, or its insertion point
 * Idea       : This is the lower bound: the first index whose value is >=
 *              target.
 * Complexity : Time O(log n)   Space O(1)
 * TODO       : same body as lower_bound.cpp and the same off-by-one: it
 *              returns the first index > target, so a target already present
 *              reports the index after it.
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