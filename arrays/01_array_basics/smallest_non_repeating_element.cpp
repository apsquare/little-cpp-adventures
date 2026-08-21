/*
 * SMALLEST NON-REPEATING ELEMENT
 *
 * Problem    : Given an array of n integers in the range 0..999, print the
 *              smallest value that appears exactly once.
 * Input      : n, then n integers
 * Output     : the smallest value with frequency 1 (nothing is printed if
 *              every value repeats)
 * Idea       : Count into a frequency array, then scan the counts in
 *              increasing order of value.
 * Complexity : Time O(n + 1000)   Space O(1000)
 */

#include<iostream>

using namespace std;

int main(){

  int n ;
  cin >> n;

  int arr[n];
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }

  int freq[1000] = {0};

  for(int i=0;i<n;i++){
    freq[arr[i]] ++;
  }

 
  for(int i=0;i<1000;i++){
   if(freq[i] == 1){
    cout << i << endl;
    return 0;
   }
  }



  


}