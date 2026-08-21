/*
 * TWO SUM IN A SORTED ARRAY (two pointers)
 *
 * Problem    : Given an array of n integers sorted in ascending order and a
 *              target, determine whether two different elements sum to the
 *              target.
 * Input      : n, then n sorted integers, then target
 * Output     : True when such a pair exists, otherwise False
 * Idea       : Start a pointer at each end. If the sum is too big move the
 *              right pointer in, if it is too small move the left one out.
 * Complexity : Time O(n)   Space O(1)
 */

#include<iostream>

using namespace std;

//! Given a sorted array and a target, determine whether there are two different elements whose sum equals the target.

int main(){

  //? Taking input
  int n ,target;
  cin >> n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }
  cin >> target;


  int left = 0;
  int right = n-1 ;

  // ? As the problem asks for two different number left != right
  while (left < right)
  {
    if(arr[left] + arr[right] == target){
      cout << "True" << endl;
      return 0;
    }else if(arr[left] + arr[right] < target){
      left ++;
    }else{
      right--;
    }
  }
  

  cout << "False" << endl;


}
