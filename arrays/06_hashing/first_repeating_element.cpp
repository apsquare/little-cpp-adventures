/*
 * FIRST REPEATING ELEMENT
 *
 * Problem    : Given an array of n integers, print the first element (by
 *              position) whose frequency is greater than one.
 * Input      : n, then n integers
 * Output     : the first repeating element, or -1 when every value is unique
 * Idea       : Count frequencies first, then scan the array in order and
 *              return the first value with a count above one.
 * Complexity : Time O(n) average   Space O(n)
 * TODO       : the answer is returned from main instead of being printed, so
 *              nothing is written to stdout.
 */

#include<iostream>
#include<unordered_map>


using namespace std;


int main(){

  int n;
  cin >> n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }

  unordered_map<int,int> freq;
  for(int i=0;i<n;i++){
    freq[arr[i]] ++;
  }

  for(int i=0;i<n;i++){
    if(freq[arr[i]] > 1){
      return arr[i];
    }
  }


  return -1;
  








}