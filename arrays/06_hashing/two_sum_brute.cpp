/*
 * TWO SUM (brute force)
 *
 * Problem    : Given an array of n integers and a target, find two different
 *              elements whose sum equals the target and print their indices.
 * Input      : n, then n integers, then target
 * Output     : the two indices, or -1 when no pair exists
 * Idea       : Check every pair (i, j) with j > i.
 * Complexity : Time O(n^2)   Space O(1)
 */

#include<iostream>
#include<unordered_map>


using namespace std;



int main(){

  int n ,target;
  cin >> n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }

  cin >> target;

  for(int i=0;i<n;i++){
    int first = arr[i];
    for(int j=i+1 ; j<n;j++){
      if(arr[j] == (target - first)){
        cout << i << " " << j << endl;
        return 0;
      }
    }
  }


  cout << -1 << endl;


}
