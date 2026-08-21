/*
 * LINEAR SEARCH
 *
 * Problem    : Given an array of n integers and a target, print the index of
 *              the first occurrence of the target, or -1 if it is not
 *              present.
 * Input      : n, then n integers, then target
 * Output     : index of the first match, else -1
 * Idea       : Scan left to right and stop at the first match.
 * Complexity : Time O(n)   Space O(1)
 */

#include<iostream>


using namespace std;

int main(){

  int n , target;
 
  cin >> n;
  int arr[n];
  
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }

  cin >> target ;
  

  


  for(int i=0;i<n;i++){
    if(arr[i] == target){
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;




}