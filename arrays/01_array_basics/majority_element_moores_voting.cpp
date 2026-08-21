/*
 * MAJORITY ELEMENT (Moore's voting)
 *
 * Problem    : Given an array of n integers, print the element that appears
 *              more than n/2 times, or -1 if there is none.
 * Input      : n, then n integers
 * Output     : the majority element, else -1
 * Idea       : Pass 1 cancels out different values to leave one candidate;
 *              pass 2 verifies that the candidate really occurs more than
 *              n/2 times.
 * Complexity : Time O(n)   Space O(1)
 */

#include<iostream>

using namespace std;

int main(){
  int n;
  cin >> n;

  int arr[n];
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }

  int candidate;
  int count =0 ;

  for(int i=0;i<n;i++){

    if(count ==0 ){
      candidate = arr[i];
    }

    if(arr[i] == candidate){
      count++;
    }else{
      count--;
    }

  }


  int fre =0 ;
  for(int i=0;i<n;i++){
    if(arr[i] == candidate){
      fre++;
    }
  }

  if(fre > n/2){
    cout << candidate ;
  }else{
    cout << -1;
  }




}