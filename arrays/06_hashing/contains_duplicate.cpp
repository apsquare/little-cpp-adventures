/*
 * CONTAINS DUPLICATE
 *
 * Problem    : Given an array of n integers, decide whether any value
 *              appears at least twice.
 * Input      : n, then n integers
 * Output     : true when a duplicate exists, otherwise false
 * Idea       : Insert into an unordered_set and stop the moment a value is
 *              already there.
 * Complexity : Time O(n) average   Space O(n)
 * TODO       : the result is returned from main (which sets the exit code)
 *              instead of being printed, so the program prints nothing.
 */

#include<iostream>
#include<unordered_set>

using namespace std;



int main(){

  int n;
  cin >> n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }

  unordered_set<int> seen;

  for(int i=0;i<n;i++){
    int current  = arr[i];
    if(seen.find(current) != seen.end()){
      return true;
    }
    seen.insert(current);
  }


  return false;






}