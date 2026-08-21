/*
 * LEADERS IN AN ARRAY (brute force)
 *
 * Problem    : An element is a leader if no element to its right is strictly
 *              greater than it. Print all the leaders. The last element is
 *              always a leader.
 * Input      : n, then n integers
 * Output     : the leaders, in left-to-right order
 * Idea       : For every element, scan everything to its right.
 * Complexity : Time O(n^2)   Space O(1)
 */

#include<iostream>

using namespace std;

int main(){

  int n;
  cin >> n ;
  int arr[n];
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }

  for(int i=0;i<n;i++){

    bool leader = true;
    for(int j=i+1;j<n;j++){
      if(arr[j] > arr[i]){
        leader = false;
        break;
      }
    }

    if(leader)
      cout << arr[i] << " ";

  }

}