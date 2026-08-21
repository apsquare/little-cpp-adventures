/*
 * TWO SUM (hash map)
 *
 * Problem    : Given an array of n integers and a target, find two different
 *              elements whose sum equals the target and print their indices.
 * Input      : n, then n integers, then target
 * Output     : the two indices, or -1 when no pair exists
 * Idea       : For each element look up target - arr[i] among the values
 *              already seen, then record the current value.
 * Complexity : Time O(n) average   Space O(n)
 * TODO       : arr[i] is never inserted into the map and the function does
 *              not return after printing, so this always falls through to
 *              -1. Add seen[arr[i]] = i at the end of the loop and return
 *              after printing the pair.
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

  unordered_map<int,int> seen;
  for(int i=0;i<n;i++){
    
    int needed = target -   arr[i];

    if(seen.find(needed) != seen.end()){
      cout << seen[needed] << " " << i << endl;
    }
  }


  cout << -1 << endl;




}